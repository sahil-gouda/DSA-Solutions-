// Problem: Detect Capital
// LeetCode Link: https://leetcode.com/problems/detect-capital/
// Author: Sahil Gouda

/*
Problem Statement:
We define the usage of capitals in a word to be correct when:
1. All letters in the word are capitals.      (e.g. "USA")
2. All letters in the word are not capitals.  (e.g. "leetcode")
3. Only the first letter in the word is capital, and all others are lowercase. (e.g. "Google")

Return true if the usage of capitals in the given word is correct.
Otherwise, return false.

------------------------------------------------------------------
Approach:
- Count the number of uppercase characters in the word.
- Three valid conditions:
    1. If no uppercase letters exist → all lowercase → valid.
    2. If all characters are uppercase → valid.
    3. If exactly one uppercase exists and it is the first letter → valid.
- Else return false.
------------------------------------------------------------------
Time Complexity: O(n)  (one pass to count uppercase letters)
Space Complexity: O(1) (constant extra space)
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCapitals = 0;

        // Count uppercase letters
        for (char &ch : word) {
            if (isupper(ch)) 
                countCapitals++;
        }

        // Check valid conditions
        if (countCapitals == 0) return true;                      // all lowercase
        if (countCapitals == word.length()) return true;          // all uppercase
        if (countCapitals == 1 && isupper(word[0])) return true;  // only first letter uppercase

        return false; // otherwise invalid
    }
};
