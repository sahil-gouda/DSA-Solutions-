// Problem: 125. Valid Palindrome
// LeetCode Link: https://leetcode.com/problems/valid-palindrome/
// Author: Sahil Gouda

/*
Problem Statement:
Given a string s, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

Example:
Input: "A man, a plan, a canal: Panama"
Output: true

Input: "race a car"
Output: false

------------------------------------------------------------------
Approach:
- Use two pointers, left starting from 0 and right starting from s.size() - 1
- Move the pointers towards the center:
    - Skip non-alphanumeric characters using isalnum()
    - Convert letters to lowercase using tolower() before comparison
    - If a mismatch is found, return false
- If pointers cross without mismatch, return true

------------------------------------------------------------------
Time Complexity: O(n)
    (Each character is visited at most once)
Space Complexity: O(1)
    (Only pointers and counters are used)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        while(left < right){
            // Skip non-alphanumeric characters
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            // Compare lowercase characters
            else if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            else{
                left++;
                right--;
            }
        }

        return true;
    }
};
