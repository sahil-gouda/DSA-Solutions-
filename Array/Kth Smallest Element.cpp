// Problem: Kth Smallest Element in Array
// Platform: GeeksforGeeks / DSA Medium
// Author: Sahil Gouda

/*
🧩 Problem Statement:
Given an array `arr[]` and an integer `k` (1 <= k <= n),
find the **kth smallest element** in the array **without using built-in sort**.

---------------------------------------------------------------
🔹 Example 1:
Input:  arr = [7, 10, 4, 3, 20, 15], k = 3
Output: 7

Explanation:
- The first 3 smallest elements in the array are [3, 4, 7]  
- 3rd smallest element = 7

---------------------------------------------------------------
💡 Approach (Max-Heap of size k):
1️⃣ Push the first k elements into a Max-Heap.  
2️⃣ For each remaining element in the array:  
   - If element < heap top → pop the top and push the element  
   - Else ignore  
3️⃣ After processing all elements, heap top = kth smallest element

---------------------------------------------------------------
⚙️ Dry Run (arr = [7, 10, 4, 3, 20, 15], k = 3):

Step 1 → Push first 3 elements → Heap = [10, 7, 4]  
Step 2 → Element 3 < 10 → Pop 10, Push 3 → Heap = [7, 4, 3]  
Step 3 → Element 20 > 7 → Ignore  
Step 4 → Element 15 > 7 → Ignore  

✅ Heap top = 7 → kth smallest element

---------------------------------------------------------------
⏱️ Time Complexity: O(n log k)
- Build heap of size k → O(k)  
- For remaining n-k elements → each insert/pop → O(log k)  
- Total = O(k + (n-k) log k) ≈ O(n log k)

💾 Space Complexity: O(k)
- Only store k elements in the heap
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // Max heap to store k smallest elements
        priority_queue<int> pq;

        // Push first k elements
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // Process remaining elements
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < pq.top()) {
                pq.pop();          // remove largest
                pq.push(arr[i]);   // insert smaller
            }
        }

        // Heap top is kth smallest element
        return pq.top();
    }
};

/*
✅ Example Run:
Input:  arr = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
*/
