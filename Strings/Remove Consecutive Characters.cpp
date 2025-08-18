// Problem: Remove Consecutive Characters
// GFG Link: https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
// Author: Sahil Gouda
// Description:
// Given a string s, remove all consecutive duplicate characters from the string.
// Example: 
// Input: s = "aabb"
// Output: "ab"
//
// Approach:
// 1. Traverse the string character by character.
// 2. Keep appending the character to result only if:
//    - It is the first character, OR
//    - It is different from the previous character.
// 3. Return the result string.
//
// Complexity Analysis:
// Time Complexity: O(n) 
//   - Single traversal of the string.
// Space Complexity: O(1) 
//   - Result string takes extra space but proportional to output, not input size.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeConsecutiveCharacter(string &s) {
        string result = "";  // Directly use string to store answer

        for (int i = 0; i < s.size(); i++) {
            // Push character if it's the first one OR different from previous
            if (i == 0 || s[i] != s[i - 1]) {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};
