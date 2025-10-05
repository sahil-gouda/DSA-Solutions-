// Problem: Reverse the Array
// Platform: GeeksforGeeks / DSA Basic
// Author: Sahil Gouda

/*
🧩 Problem Statement:
Given an array of integers, reverse the array in place.

You have to modify the array such that the first element becomes the last,
the second becomes the second-last, and so on.

---------------------------------------------------------------
🔹 Example 1:
Input:  arr = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]

🔹 Example 2:
Input:  arr = [10, 20, 30]
Output: [30, 20, 10]

---------------------------------------------------------------
💡 Approach:
- Use two-pointer technique:
  • One pointer `start` at the beginning of the array.
  • Another pointer `end` at the end.
- Swap elements at these two positions, then move both inward.
- Repeat until `start >= end`.

---------------------------------------------------------------
⚙️ Dry Run (arr = [1, 2, 3, 4, 5]):
Step 1 → swap(1, 5) → [5, 2, 3, 4, 1]
Step 2 → swap(2, 4) → [5, 4, 3, 2, 1]
Step 3 → stop (start == end)

---------------------------------------------------------------
⏱️ Time Complexity:  O(n)
💾 Space Complexity: O(1)  (in-place reversal)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        // Reverse the array using two-pointer approach
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};

/*
✅ Example Run:
Input:  [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
*/
