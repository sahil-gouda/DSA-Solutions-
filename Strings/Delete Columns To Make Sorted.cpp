// Problem: 944. Delete Columns to Make Sorted
// LeetCode Link: https://leetcode.com/problems/delete-columns-to-make-sorted/
// Author: Sahil Gouda

/*
Problem Statement:
You are given an array of n strings of equal length.
A column is considered "sorted" if the characters in that column are
in non-decreasing order from top to bottom.
Your task is to determine the number of columns that are NOT sorted
and must be deleted.

Example:
Input: ["cba","daf","ghi"]
- Column 0: c, d, g → sorted
- Column 1: b, a, h → not sorted → delete
- Column 2: a, f, i → sorted
Output: 1

------------------------------------------------------------------
Approach:
- Let n = number of strings (rows), k = length of each string (columns).
- For each column:
    - Traverse through all rows and check if characters are in non-decreasing order.
    - If a violation is found, increment the deletion count and break for that column.
- Finally, return the count.

------------------------------------------------------------------
Time Complexity: O(n * k)  
    (We scan each column across all rows)
Space Complexity: O(1)  
    (Only a counter is used)
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();        // number of rows (strings)
        int k = strs[0].size();     // number of columns (characters per string)
        int count = 0;

        // Traverse each column
        for (int i = 0; i < k; i++) {
            // Check if this column is sorted from top to bottom
            for (int j = 1; j < n; j++) {
                if (strs[j][i] < strs[j-1][i]) {
                    count++;    // column not sorted → must delete
                    break;      // move to next column
                }
            }
        }

        return count;
    }
};
