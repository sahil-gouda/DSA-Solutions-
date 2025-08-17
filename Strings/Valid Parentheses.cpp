// Problem: 20. Valid Parentheses
// LeetCode Link: https://leetcode.com/problems/valid-parentheses/
// Author: Sahil Gouda

/*
Problem Statement:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

A string is valid if:
1. Open brackets are closed by the same type of brackets.
2. Open brackets are closed in the correct order.

Example:
Input: "()"
Output: true

Input: "([)]"
Output: false

------------------------------------------------------------------
Approach:
- Use a stack to keep track of opening brackets.
- Traverse the string character by character:
    - If it's an opening bracket '(', '{', '[', push it onto the stack.
    - If it's a closing bracket ')', '}', ']':
        - If stack is empty, return false (no matching opening bracket).
        - Pop the top of the stack and check if it matches the closing bracket.
        - If mismatch, return false.
- After traversal, if the stack is empty, return true (all brackets matched).
- Otherwise, return false.

------------------------------------------------------------------
Time Complexity: O(n)
    (Each character is pushed and popped at most once)
Space Complexity: O(n)
    (Stack may contain up to n/2 opening brackets)
*/

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Stack to store opening brackets

        for(char c : s) {
            // Push opening brackets onto the stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Process closing brackets
            else {
                if(st.empty()) return false; // No matching opening bracket
                char top = st.top();
                st.pop();
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '['))
                    return false; // Mismatch found
            }
        }

        return st.empty(); // True if all brackets matched
    }
};
