// Problem: Check If Two String Arrays are Equivalent
// LeetCode Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Author: Sahil Gouda

/*
Problem Statement:
Given two string arrays word1 and word2, return true if the two arrays
represent the same string, and false otherwise.

A string is represented by concatenating all the strings in the array in order.

Example 1:
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation: word1 -> "abc", word2 -> "abc" → same string

Example 2:
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false

------------------------------------------------------------------
Approach:
- Instead of concatenating (which takes extra memory),
  compare characters one by one directly.
- Use 4 indexes:
    - w1i → current string index in word1
    - w2i → current string index in word2
    - i   → character index in current string of word1
    - j   → character index in current string of word2
- Traverse both arrays simultaneously:
    - If characters differ → return false.
    - If a string finishes, move to the next string.
- At the end, both arrays must be fully traversed for equality.

------------------------------------------------------------------
Time Complexity: O(N)  (N = total number of characters across both arrays)
Space Complexity: O(1) (no extra space used)
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        
        int w1i = 0, w2i = 0; // indexes for word1 & word2 strings
        int i = 0, j = 0;     // indexes for characters inside those strings
        
        while (w1i < n && w2i < m) {
            // Compare current characters
            if (word1[w1i][i] != word2[w2i][j])
                return false;
            
            // Move to next character
            i++;
            j++;
            
            // If current string of word1 is finished → move to next string
            if (i == word1[w1i].size()) {
                i = 0;
                w1i++;
            }
            
            // If current string of word2 is finished → move to next string
            if (j == word2[w2i].size()) {
                j = 0;
                w2i++;
            }
        }
        
        // Both word1 and word2 must be fully traversed
        return (w1i == n && w2i == m);
    }
};
