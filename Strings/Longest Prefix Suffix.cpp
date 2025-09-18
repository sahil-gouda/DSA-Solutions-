// Problem: Longest Proper Prefix which is also Suffix (LPS)
// Platform: Common DSA Problem (used in KMP Algorithm)
// Author: Sahil Gouda

/*
Problem Statement:
Given a string s, find the length of the longest proper prefix 
which is also a suffix. A proper prefix cannot be equal to the 
entire string itself.

Example:
Input: s = "abab"
Output: 2
Explanation: "ab" is both a prefix and suffix.

Input: s = "aabcdaabc"
Output: 4
Explanation: "aabc" is both a prefix and suffix.

------------------------------------------------------------------
Approach (Two Pointers):
- Use two pointers: prefix and suffix.
- prefix starts from 0, suffix starts from 1.
- Compare characters:
    - If they match → move both forward, increase count.
    - If mismatch → reset prefix = 0, shift suffix window forward.
- Keep track of maximum matched length.

Note:
This approach is a naive O(n^2) solution.
The optimized way is to use the KMP prefix-function (O(n)).

------------------------------------------------------------------
Time Complexity: O(n^2)   (worst case)
Space Complexity: O(1)    (constant extra space)
*/

class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.size();
        int prefix = 0, suffix = 1, pos = 1, count = 0;

        // Compare prefix and suffix
        while (prefix < n && suffix < n) {
            if (s[prefix] == s[suffix]) {
                prefix++;
                suffix++;
                count++;
            } else {
                // reset and shift suffix
                prefix = 0;
                pos++;
                suffix = pos;
                count = 0;
            }
        }
        return count;
    }
};
