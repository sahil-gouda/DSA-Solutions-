// Problem: Determine if two strings are "close"
// LeetCode Link: https://leetcode.com/problems/determine-if-two-strings-are-close/
// Author: Sahil Gouda

/*
Explanation:
Two strings are considered "close" if:
1. They have the exact same set of characters.
2. The frequency of characters can be rearranged to match.

Steps:
- Count frequency of each character for both strings.
- Check if both strings use the same set of characters.
- Sort both frequency arrays and compare.
- If both match, strings are close.
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // Step 1: Length check
        if (n != m) return false;

        // Step 2: Frequency arrays of size 26 (for a-z)
        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequencies
        for (int i = 0; i < n; i++) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        // Step 3: Ensure same set of characters are used
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || 
                (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        // Step 4: Sort frequencies to compare distributions
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Step 5: Final check
        return freq1 == freq2;
    }
};
