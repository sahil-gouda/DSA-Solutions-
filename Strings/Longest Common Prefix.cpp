// Problem: Longest Common Prefix
// LeetCode Link: https://leetcode.com/problems/longest-common-prefix/
// Author: Sahil Gouda

/*
Problem Statement:
Given an array of strings, find the longest common prefix (LCP) among them.
If there is no common prefix, return an empty string "".

Example:
Input: ["flower","flow","flight"]
Output: "fl"

Input: ["dog","racecar","car"]
Output: ""
------------------------------------------------------------------
Approach: Horizontal Scanning
1. Edge case: If the input vector is empty, return "".
2. Initialize prefix with the first string in the array.
3. Iterate over the rest of the strings:
   - While the current string does not start with the prefix:
       - Remove the last character from the prefix.
       - If the prefix becomes empty, return "".
4. After checking all strings, the remaining prefix is the LCP.

------------------------------------------------------------------
Time Complexity: O(S) 
- S = sum of all characters in all strings. 
- In the worst case, we compare all characters of all strings.

Space Complexity: O(1) extra space 
- Only the prefix string is used; no additional data structures needed.
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: empty input
        if (strs.empty()) return "";

        // Initialize prefix with the first string
        string prefix = strs[0];

        // Compare prefix with each string in the vector
        for (int i = 1; i < strs.size(); i++) {
            // Reduce prefix until it matches the start of the current string
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                // If prefix becomes empty, no common prefix exists
                if (prefix.empty()) return "";
            }
        }

        return prefix; // Return the longest common prefix
    }
};
