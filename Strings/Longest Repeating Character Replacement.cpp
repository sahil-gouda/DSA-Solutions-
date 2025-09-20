/*
Problem: Longest Repeating Character Replacement
Platform: LeetCode (https://leetcode.com/problems/longest-repeating-character-replacement/)
Approach: Sliding Window + Frequency Array
Author: YourName
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);   // Frequency array for A-Z characters
        int left = 0;              // Left pointer of sliding window
        int maxFreq = 0;           // Count of most frequent char in current window
        int ans = 0;               // Result (max valid window size)

        // Expand window with right pointer
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If replacements needed > k, shrink from left
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update maximum answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

/*
🔎 Approach:
1. Maintain a sliding window [left...right].
2. Track frequencies of characters inside the window using freq[26].
3. maxFreq = frequency of the most common character in the window.
4. Condition: (window size - maxFreq) ≤ k  
   → means we can replace at most 'k' chars to make the whole window same.
5. If condition breaks, shrink window by moving 'left'.

⏱️ Time Complexity: O(n)
- Each character processed once by 'right' and at most once by 'left'.

💾 Space Complexity: O(26) ≈ O(1)
- Only 26 characters tracked.

📌 Example:
Input:  s = "AABABBA", k = 1
Output: 4  
Reason: Replace one 'A' → substring "ABBB" has length 4.
*/
