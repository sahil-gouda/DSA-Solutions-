// Problem: Insert Interval (Merge New Interval into Sorted Intervals)
// Platform: LeetCode / InterviewBit / GFG
// Author: Sahil Gouda

/*
🧩 Problem:
Given non-overlapping, sorted intervals `intervals[]` and a new interval `newInterval`,  
insert `newInterval` into the correct position and merge if overlapping.

---------------------------------------------------------------
🔹 Example:
Input:
intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
newInterval = [4, 8]

Output:
[[1, 2], [3, 10], [12, 16]]

Explanation:
Overlapping ones [3,5],[6,7],[8,10],[4,8] → merged into [3,10]

---------------------------------------------------------------
💡 Approach:
1️⃣ Add all intervals ending before newInterval starts.  
2️⃣ Merge all intervals overlapping with newInterval.  
   → Update:
      newInterval.start = min(newInterval.start, curr.start)
      newInterval.end   = max(newInterval.end, curr.end)
3️⃣ Add all intervals starting after newInterval ends.

---------------------------------------------------------------
⚙️ Dry Run:
intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]

→ Step 1: Add [[1,2]]  
→ Step 2: Merge [3,5],[6,7],[8,10] → becomes [3,10]  
→ Step 3: Add [12,16]  
✅ Final = [[1,2],[3,10],[12,16]]

---------------------------------------------------------------
⏱️ TC: O(n) 💾 SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int i = 0, n = intervals.size();

        // 1️⃣ Add intervals before newInterval
        while (i < n && intervals[i].end < newInterval.start)
            ans.push_back(intervals[i++]);

        // 2️⃣ Merge overlapping intervals
        while (i < n && intervals[i].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            i++;
        }
        ans.push_back(newInterval);

        // 3️⃣ Add remaining intervals
        while (i < n)
            ans.push_back(intervals[i++]);

        return ans;
    }
};

/*
✅ Example Run:
intervals = [[1,3],[6,9]]
newInterval = [2,5]
Output: [[1,5],[6,9]]
*/
