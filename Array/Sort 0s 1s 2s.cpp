// Problem: Sort an Array of 0s, 1s, and 2s
// Platform: GeeksforGeeks / DSA Medium
// Author: Sahil Gouda

/*
🧩 Problem Statement:
Given an array `arr[]` consisting of only 0s, 1s, and 2s,
sort the array in-place such that all 0s come first, 
followed by all 1s, then all 2s.

---------------------------------------------------------------
🔹 Example 1:
Input:  arr = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]

🔹 Example 2:
Input:  arr = [2, 0, 1]
Output: [0, 1, 2]

---------------------------------------------------------------
💡 Approach (Dutch National Flag Algorithm):
1️⃣ Initialize three pointers:
   - `i` → boundary for 0s (start of array)
   - `mid` → current element to process
   - `j` → boundary for 2s (end of array)

2️⃣ Traverse array with `mid` pointer:
   - If arr[mid] == 0 → swap arr[i] & arr[mid], increment i and mid
   - If arr[mid] == 1 → mid++ (already in correct position)
   - If arr[mid] == 2 → swap arr[mid] & arr[j], decrement j (don't increment mid because new element at mid needs processing)

3️⃣ Stop when mid > j. Array is now sorted.

---------------------------------------------------------------
⚙️ Dry Run (arr = [0, 1, 2, 0, 1, 2]):

Initial: i=0, mid=0, j=5 → [0,1,2,0,1,2]

Step 1 → arr[mid]=0 → swap(arr[0], arr[0]) → i=1, mid=1 → [0,1,2,0,1,2]  
Step 2 → arr[mid]=1 → mid=2 → [0,1,2,0,1,2]  
Step 3 → arr[mid]=2 → swap(arr[2], arr[5]) → j=4 → [0,1,2,0,1,2]  
Step 4 → arr[mid]=2 → swap(arr[2], arr[4]) → j=3 → [0,1,1,0,2,2]  
Step 5 → arr[mid]=1 → mid=3 → [0,1,1,0,2,2]  
Step 6 → arr[mid]=0 → swap(arr[1], arr[3]) → i=2, mid=4 → [0,0,1,1,2,2]  

✅ Array Sorted: [0,0,1,1,2,2]

---------------------------------------------------------------
⏱️ Time Complexity: O(n)
- Each element is processed **exactly once**.

💾 Space Complexity: O(1)
- In-place sorting, no extra space used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int i = 0;       // Boundary for 0s
        int mid = 0;     // Current element
        int j = n - 1;   // Boundary for 2s

        while(mid <= j) {
            if(arr[mid] == 0) {
                swap(arr[i], arr[mid]);
                i++;
                mid++;
            }
            else if(arr[mid] == 1) {
                mid++;
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[j]);
                j--;
            }
        }
    }
};

/*
✅ Example Run:
Input:  arr = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
*/
