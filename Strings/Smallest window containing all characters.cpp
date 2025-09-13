// Problem: Smallest Window in a String containing all characters of another string
// GFG Link: https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
// Author: Sahil Gouda

/*
Problem Statement:
Given two strings s and p, find the smallest substring in s consisting 
of all the characters (including duplicates) of string p. 
If no such substring exists, return an empty string.

Example:
Input: s = "timetopractice", p = "toc"
Output: "toprac"

Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"

------------------------------------------------------------------
Approach:
- Use the sliding window technique with two pointers.
- Maintain frequency counts for both p and the current window in s.
- Expand the right pointer to include characters until all chars of p are covered.
- Then shrink the window from the left to make it minimal while still valid.
- Track the smallest valid window found.

------------------------------------------------------------------
Optimization:
- Instead of using a map, we can use a fixed-size frequency array of size 26 
  since the strings contain only lowercase English letters.
- Early contraction of the window improves efficiency.

------------------------------------------------------------------
Time Complexity: O(n)   (n = length of string s)
Space Complexity: O(26) ≈ O(1) (constant space for frequency arrays)
*/

class Solution {
public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        int n = s.size(), m = p.size();
        int start = -1, len = INT_MAX, count1 = 0, count2 = 0, j = 0;

        vector<int> fors(26, 0), forp(26, 0);

        // Step 1: Count frequency of chars in p
        for (int i = 0; i < m; i++) {
            forp[p[i] - 'a']++;
            if (forp[p[i] - 'a'] == 1) count1++;
        }

        // Step 2: Sliding window on s
        for (int i = 0; i < n; i++) {
            fors[s[i] - 'a']++;

            if (fors[s[i] - 'a'] == forp[s[i] - 'a']) count2++;

            // Step 3: Contract window from left
            while (count2 == count1 && j <= i) {
                if (i - j + 1 < len) {
                    start = j;
                    len = i - j + 1;
                }
                fors[s[j] - 'a']--;
                if (fors[s[j] - 'a'] < forp[s[j] - 'a']) count2--;
                j++;
            }
        }

        if (start == -1) return "";
        return s.substr(start, len);
    }
};
