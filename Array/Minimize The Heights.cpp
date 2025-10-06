// Problem: Minimize the Heights II
// GFG Link: https://practice.geeksforgeeks.org/problems/minimize-the-heights-ii/0
// Author: Sahil Gouda

/*
------------------------------------------------------------------
🧩 Problem Statement:
You are given an array `arr[]` denoting heights of `n` towers and 
a positive integer `k`. 

For each tower, you must perform exactly one of the following 
operations exactly once:
  - Increase the height by `k`
  - Decrease the height by `k`

Find the minimum possible difference between the height of the 
shortest and tallest towers after modification.

⚠️ Note:
- Every tower must be modified (increase or decrease exactly once).
- The final heights should not be negative.

------------------------------------------------------------------
💡 Example:

Input:
k = 2, arr[] = [1, 5, 8, 10]

Possible modification:
[1+k, 5-k, 8-k, 10-k] → [3, 3, 6, 8]
Minimum difference = 8 - 3 = 5

Output: 5

------------------------------------------------------------------
🧠 Approach (Greedy Logic):

1️⃣ Sort the array — because the order of heights matters for extreme values.
2️⃣ Initial difference = arr[n-1] - arr[0]
3️⃣ Try to minimize this gap by:
    - Increasing smaller heights by `k`
    - Decreasing larger heights by `k`
4️⃣ Let:
      small = arr[0] + k   // potential new minimum
      big   = arr[n-1] - k // potential new maximum
5️⃣ Traverse the array:
      For every index i,
        minVal = min(small, arr[i+1] - k)
        maxVal = max(big, arr[i] + k)
        If minVal < 0 → skip (invalid)
        Update answer = min(answer, maxVal - minVal)

------------------------------------------------------------------
✅ Intuition:
We’re trying to “shift” the middle portion of the array optimally 
so that both the smallest and largest towers come closer while 
ensuring no tower goes below height 0.

------------------------------------------------------------------
⏱️ Time Complexity:  O(n log n)
💾 Space Complexity: O(1)
------------------------------------------------------------------
*/

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        // Step 1: Sort the array
        sort(arr, arr + n);

        // Step 2: Initialize result with current difference
        int ans = arr[n - 1] - arr[0];

        // Step 3: Compute potential small and big values
        int small = arr[0] + k;
        int big = arr[n - 1] - k;

        // Step 4: Traverse and find the optimal difference
        for (int i = 0; i < n - 1; i++) {
            int minVal = min(small, arr[i + 1] - k);
            int maxVal = max(big, arr[i] + k);

            if (minVal < 0) continue;  // Skip invalid cases

            ans = min(ans, maxVal - minVal);
        }

        return ans;
    }
};
