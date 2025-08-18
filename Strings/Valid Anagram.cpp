// Problem: 242. Valid Anagram
// LeetCode Link: https://leetcode.com/problems/valid-anagram/
// Author: Sahil Gouda
// Description:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of another word.
//
// Approach:
// 1. If lengths differ, they cannot be anagrams.
// 2. Use a frequency array of size 26 to count occurrences of each char in 's'.
// 3. Decrement counts while traversing 't'.
// 4. If any count goes negative, return false (extra char in 't').
// 5. If all counts balance to zero, return true.
//
// Complexity Analysis:
// Time Complexity: O(n) 
//   - where n = length of string s (or t).
//   - One pass over s, one pass over t.
// Space Complexity: O(1)
//   - Only an array of size 26 is used, independent of input size.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Length check
        if (s.size() != t.size()) return false;

        // Step 2: Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Step 3: Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 4: Decrease counts for characters of t
        for (char c : t) {
            freq[c - 'a']--;

            // If any count becomes negative → not an anagram
            if (freq[c - 'a'] < 0) {
                return false;
            }
        }

        // Step 5: If all balanced → it’s an anagram
        return true;
    }
};
