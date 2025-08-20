/*
Problem: Length of Longest Substring Without Repeating Characters
Platform: LeetCode / Any C++ environment
Approach: Sliding Window + Hash Map
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // Map to store last index of each character
        int left = 0;                // Window start
        int maxLen = 0;              // Maximum length of substring without repeating chars

        for (int right = 0; right < s.size(); right++) {
            char c = s[right]; // Current character

            // If character is already in the current window, move left pointer
            if (mp.count(c) && mp[c] >= left) {
                left = mp[c] + 1;
            }

            // Update the last index of current character
            mp[c] = right;

            // Update the maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

/*
Approach:
1. Use a sliding window with two pointers: left and right.
2. Keep track of the last index of each character using a hash map.
3. If a character repeats within the current window, move 'left' to last_index + 1.
4. Expand the window with 'right' pointer and update max length at each step.

Time Complexity: O(n)
- Each character is visited at most twice (once by right, once by left).

Space Complexity: O(min(n, charset))
- Hash map stores characters of the current window.
- Charset = number of unique characters (for ASCII it's max 128).

Example:
Input: s = "abcabcbb"
Output: 3  // "abc"
*/
