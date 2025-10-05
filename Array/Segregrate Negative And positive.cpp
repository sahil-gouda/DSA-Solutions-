// Problem: Segregate Negative and Positive Numbers
// Platform: GeeksforGeeks / DSA Medium
// Author: Sahil Gouda

/*
🧩 Problem Statement:
Given an array `arr[]`, move all negative numbers to the end
while maintaining the relative order of positive numbers and negatives.

---------------------------------------------------------------
🔹 Example 1:
Input:  arr = [1, -1, 3, -2, -3, 4, 5]
Output: [1, 3, 4, 5, -1, -2, -3]

Explanation:
- All positive numbers appear first in the **same order**.
- All negative numbers appear at the **end in the same order**.

---------------------------------------------------------------
💡 Approach:
1️⃣ Create an auxiliary vector `negative` to store negative numbers.  
2️⃣ Traverse the array:
   - If element ≥ 0 → place it at the current position `j`  
   - If element < 0 → store in `negative` vector  
3️⃣ After traversal, append all negative numbers from `negative` vector to the array.

This approach **maintains relative order** (stable).

---------------------------------------------------------------
⚙️ Dry Run (arr = [1, -1, 3, -2, -3, 4, 5]):

Step 1 → positive elements placed in order: [1,3,4,5,_,_,_]  
Step 2 → negative vector = [-1, -2, -3]  
Step 3 → append negatives → [1,3,4,5,-1,-2,-3]

✅ Result: [1,3,4,5,-1,-2,-3]

---------------------------------------------------------------
⏱️ Time Complexity: O(n)
- Traverse array once + traverse negative vector once → Linear

💾 Space Complexity: O(k)
- Extra space used for `negative` vector (k = number of negatives)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void segregateElements(vector<int>& arr) {
        vector<int> negative;  // store negative numbers
        int n = arr.size();
        int j = 0;  // index for placing positive numbers

        // Traverse array and separate positives and negatives
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0)
                negative.push_back(arr[i]);
            else {
                arr[j] = arr[i];
                j++;
            }
        }

        // Append negatives at the end
        for(int i = 0; i < negative.size(); i++) {
            arr[j] = negative[i];
            j++;
        }
    }
};

/*
✅ Example Run:
Input:  arr = [1, -1, 3, -2, -3, 4, 5]
Output: [1, 3, 4, 5, -1, -2, -3]
*/
