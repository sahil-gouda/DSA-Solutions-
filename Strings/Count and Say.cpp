// Problem: Count and Say
// LeetCode Link: https://leetcode.com/problems/count-and-say/
// Author: Sahil Gouda

/*
Problem Statement:
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
- countAndSay(1) = "1"
- countAndSay(n) is the way you would "say" the string from countAndSay(n-1).

For example:
countAndSay(1) = "1"
countAndSay(2) = "11"  -> one 1
countAndSay(3) = "21"  -> two 1s
countAndSay(4) = "1211"-> one 2, one 1

------------------------------------------------------------------
Approach:
- Base case: if n == 1 return "1".
- Recursively compute countAndSay(n-1).
- Parse the string:
    - Count consecutive repeating digits.
    - Append "count + digit" into the result string.
- Return the result.

------------------------------------------------------------------
Time Complexity: O(m)  (m = length of generated string for n)
Space Complexity: O(m)  (for storing result string)
*/

class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";

        // Get the previous string
        string say = countAndSay(n - 1);
        string result = "";

        // Process the previous string
        for (int i = 0; i < say.length(); i++) {
            char ch = say[i];
            int count = 1;

            // Count consecutive same digits
            while (i < say.length() - 1 && say[i] == say[i + 1]) {
                count++;
                i++;
            }

            // Append "count + digit" to result
            result += to_string(count) + string(1, ch);
        }

        return result;
    }
};
