// Problem: String Compression
// LeetCode Link: https://leetcode.com/problems/string-compression/
// Author: Sahil Gouda

/*
Problem Statement:
Given an array of characters chars, compress it using the following algorithm:
- Begin with an empty string s.
- For each group of consecutive repeating characters in chars:
    - If the group's length is 1, append the character to s.
    - Otherwise, append the character followed by the group's length.
- Modify the input array chars in-place.
- The length after compression must be returned.
- Any extra characters beyond the returned length are not considered.

Example:
Input: chars = ['a','a','b','b','c','c','c']
Output: 6
Explanation: The compressed array becomes ['a','2','b','2','c','3']

------------------------------------------------------------------
Approach:
- Use two pointers:
    i → traverse the array
    index → position to insert the compressed result
- For each group of same characters:
    1. Count its frequency.
    2. Insert the character at `index`.
    3. If frequency > 1, convert frequency to string and insert digits.
- Continue until the array ends.
- Return `index` as the new length.

------------------------------------------------------------------
Time Complexity: O(n)  (each character processed once)
Space Complexity: O(1) (in-place compression)
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;  // position to insert compressed result
        int i = 0;      // pointer to traverse chars

        while (i < n) {
            char curr_char = chars[i];
            int count = 0;

            // Count frequency of current character
            while (i < n && chars[i] == curr_char) {
                count++;
                i++;
            }

            // Place the character
            chars[index] = curr_char;
            index++;

            // If frequency > 1, place its digits
            if (count > 1) {
                string count_str = to_string(count);
                for (char &ch : count_str) {
                    chars[index] = ch;
                    index++;
                }
            }
        }

        return index; // final compressed length
    }
};
