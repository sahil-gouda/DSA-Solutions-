// Problem: Make The String Great
// Link: https://leetcode.com/problems/make-the-string-great/
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string makeGood(string s) {
        string result = "";
        for(char &ch : s) {
            if(!result.empty() && 
               (result.back() + 32 == ch || result.back() - 32 == ch)) {
                // If last char is same letter but different case, remove it
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result; 
    }
};
