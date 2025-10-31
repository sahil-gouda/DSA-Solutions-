// Problem: Minimum Number of Jumps to Reach End
// Platform: GeeksforGeeks / DSA Medium
// Author: Sahil Gouda

/*
🧩 Problem Statement:
You are given an array `arr[]` of size `N` where each element represents
the **maximum number of steps** you can jump forward from that index.
Find the **minimum number of jumps** required to reach the last index
starting from index 0.

If it's impossible to reach the end, return -1.

---------------------------------------------------------------
🔹 Example 1:
Input:  arr = [1, 4, 3, 2, 6, 7]
Output: 2

Explanation:
- Jump 1 step from index 0 → index 1  
- Then jump 4 steps from index 1 → index 5 (end)
✅ Total jumps = 2

---------------------------------------------------------------
💡 Approach (Greedy — Jump Range Tracking):
1️⃣ Maintain three variables:
   - `maxi`: The farthest index reachable so far.
   - `choice`: End of the current jump’s range.
   - `jumps`: Number of jumps made so far.

2️⃣ Traverse the array (till n-1):
   - Update `maxi = max(maxi, arr[i] + i)`  
   - When `i == choice`, it means we’ve reached the end of our current jump range:
       - Increment jump count.
       - Update `choice = maxi` (new jump range).

3️⃣ After loop ends:
   - If `choice >= n-1` → we can reach the end → return `jumps`.
   - Else → return `-1`.

---------------------------------------------------------------
⚙️ Dry Run (arr = [1, 4, 3, 2, 6, 7]):

i = 0 → maxi = max(0, 1+0)=1 → i==choice(0) → choice=1, jumps=1  
i = 1 → maxi = max(1, 4+1)=5 → i==choice(1) → choice=5, jumps=2  
✅ choice (5) >= n-1 (5) → return 2

---------------------------------------------------------------
⏱️ Time Complexity: O(n)
- Single pass through the array

💾 Space Complexity: O(1)
- Uses only constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;    // farthest reachable index
        int choice = 0;  // end of current jump range
        int jumps = 0;   // jump count

        for (int i = 0; i < n - 1; i++) {
            maxi = max(maxi, arr[i] + i);

            // when we reach the end of our current range
            if (i == choice) {
                choice = maxi;
                jumps++;
            }
        }

        if (choice >= n - 1)
            return jumps;

        return -1;
    }
};

/*
✅ Example Run:
Input:  arr = [1, 4, 3, 2, 6, 7]
Output: 2
*/
