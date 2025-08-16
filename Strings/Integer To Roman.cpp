// Problem: Integer to Roman
// LeetCode Link: https://leetcode.com/problems/integer-to-roman/
// Author: Sahil Gouda

/*
Problem Statement:
Given an integer, convert it to a Roman numeral.

Roman numerals are represented by seven different symbols:
I (1), V (5), X (10), L (50), C (100), D (500), M (1000).

Rules:
- Numbers are formed by combining symbols and adding values.
- But in special cases, subtraction is used:
    - 4  -> IV
    - 9  -> IX
    - 40 -> XL
    - 90 -> XC
    - 400 -> CD
    - 900 -> CM

Example:
Input: num = 1994
Output: "MCMXCIV"
Explanation: 1000 -> "M", 900 -> "CM", 90 -> "XC", 4 -> "IV"

------------------------------------------------------------------
Approach:
- Use two arrays:
    1. `val` → values of Roman numerals in descending order.
    2. `sym` → corresponding Roman numeral strings.
- Traverse the arrays:
    - While current `num >= val[i]`, append the symbol to result and subtract.
- Return the result.

------------------------------------------------------------------
Time Complexity: O(n)  (n = number of Roman symbols added, bounded ~15)
Space Complexity: O(1) (constant space)
*/

class Solution {
public:
    string intToRoman(int num) {
        // Values and corresponding Roman symbols
        vector<int> val =    {1000, 900, 500, 400, 100, 90,  50,  40, 10, 9, 5, 4, 1};
        vector<string> sym = {"M",  "CM","D", "CD", "C", "XC","L", "XL","X","IX","V","IV","I"};
        
        string result = "";

        // Greedily subtract the largest possible value
        for (int i = 0; i < val.size(); i++) {
            while (num >= val[i]) {
                result += sym[i];
                num -= val[i];
            }
        }

        return result;
    }
};
