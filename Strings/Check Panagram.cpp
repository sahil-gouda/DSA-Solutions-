// Problem: Check if the Sentence Is Pangram
// LeetCode Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Author: Sahil Gouda

/*
Problem Statement:
A pangram is a sentence where every letter of the English alphabet 
appears at least once.

Given a string sentence containing only lowercase English letters, 
return true if sentence is a pangram, or false otherwise.

Example:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true

Input: sentence = "leetcode"
Output: false

------------------------------------------------------------------
Approach:
- Use a hash map (or set) to count unique characters.
- Traverse the string and insert every character into the map.
- If the map contains all 26 letters, return true.
- Otherwise, return false.

------------------------------------------------------------------
Optimization:
- Instead of unordered_map, we can use a boolean array of size 26 
  for slightly better performance.

------------------------------------------------------------------
Time Complexity: O(n)   (n = length of sentence)
Space Complexity: O(26) ≈ O(1) (constant space for 26 letters)
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mp;

        // Count occurrences of each character
        for (char c : sentence) {
            mp[c]++;
        }

        // Check if we have all 26 alphabets
        return mp.size() == 26;
    }
};
