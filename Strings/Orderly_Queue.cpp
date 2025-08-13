// Problem Link: https://leetcode.com/problems/orderly-queue/
// Approach:
// - If k > 1 → We can sort the string completely, since swapping is not restricted.
// - If k == 1 → We can only rotate the string, so we check all possible rotations and take the lexicographically smallest.
// Time Complexity: O(n^2) for k == 1, O(n log n) for k > 1
// Space Complexity: O(1)

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            // If k > 1, sorting gives smallest possible string
            sort(begin(s), end(s));
            return s;
        }
        
        string result = s;
        // Try all rotations and find the smallest
        for (int i = 1; i < s.length(); i++) {
            string temp = s.substr(i) + s.substr(0, i);
            result = min(result, temp);
        }
        
        return result;
    }
};
