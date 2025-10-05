// Problem: Rotate Array by One (Clockwise)
// Platform: GeeksforGeeks
// Author: Sahil Gouda

/*
Problem Statement:
Given an array 'arr', rotate the array by one position in the clockwise direction.

Clockwise rotation means:
- The last element moves to the first position.
- All other elements shift one position to the right.

------------------------------------------------------------------
Example:
Input:  arr = [1, 2, 3, 4, 5]
Output: [5, 1, 2, 3, 4]

Explanation:
After rotating, last element 5 moves to front, and the rest shift right.

------------------------------------------------------------------
Approach (Your Attempt):
- Use a while loop to iterate through all indices.
- Swap each element with the last element.
- This approach uses the swap() function to manipulate array elements.

⚠️ Note:
This logic does not perform a correct rotation.
It repeatedly swaps elements with the last one, resulting in a scrambled array.

------------------------------------------------------------------
Correct Approach:
1. Store the last element in a variable.
2. Shift every element one step right.
3. Place the stored last element at the beginning.

------------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<int> &arr) {
        // Your current implementation
        int i = 0;
        int n = arr.size();
        while (i < n) {
            swap(arr[i], arr[n - 1]);
            i++;
        }
    }
};
