// Problem: Find Minimum and Maximum in an Array
// Platform: GeeksforGeeks
// Difficulty: Basic
// Author: Sahil Gouda

/*
🧩 Problem Statement:
Given an array `arr[]`, your task is to find the **minimum** and **maximum**
elements present in the array.

---------------------------------------------------------------
🔹 Example 1:
Input:  arr = [1, 4, 3, -5, -4, 8, 6]
Output: [-5, 8]

Explanation:
- The smallest (minimum) element = -5  
- The largest (maximum) element  = 8

---------------------------------------------------------------
💡 Approach:
1️⃣ Initialize two variables:
   - `minElement = arr[0]`
   - `maxElement = arr[0]`

2️⃣ Traverse the array from index 1 to n-1:
   - If `arr[i] < minElement`, update `minElement = arr[i]`
   - If `arr[i] > maxElement`, update `maxElement = arr[i]`

3️⃣ Return both values as the answer.

---------------------------------------------------------------
⚙️ Dry Run (arr = [1, 4, 3, -5, -4, 8, 6]):

Start:
min = 1, max = 1

→ Compare 4 → min = 1, max = 4  
→ Compare 3 → min = 1, max = 4  
→ Compare -5 → min = -5, max = 4  
→ Compare -4 → min = -5, max = 4  
→ Compare 8 → min = -5, max = 8  
→ Compare 6 → min = -5, max = 8  

✅ Final Output: [-5, 8]

---------------------------------------------------------------
⏱️ Time Complexity: O(n)
👉 We traverse the array once and compare each element → Linear time.

💾 Space Complexity: O(1)
👉 Only two extra variables (`minElement`, `maxElement`) are used, 
   regardless of input size → Constant space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getMinMax(vector<int>& arr) {
        int minElement = arr[0];
        int maxElement = arr[0];

        // Traverse the array once
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < minElement) 
                minElement = arr[i];
            if (arr[i] > maxElement) 
                maxElement = arr[i];
        }

        return {minElement, maxElement};
    }
};

/*
✅ Example Run:
Input:  [1, 4, 3, -5, -4, 8, 6]
Output: [-5, 8]
*/
