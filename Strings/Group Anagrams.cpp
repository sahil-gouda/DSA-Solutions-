// Problem: Group Anagrams
// LeetCode Link: https://leetcode.com/problems/group-anagrams/
// Author: Sahil Gouda

/*
Problem Statement:
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters 
of a different word or phrase, typically using all the original letters exactly once.

Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

------------------------------------------------------------------
Approach:
- Use a hash map where:
    Key   = sorted version of the string
    Value = list of all words that match this sorted key
- Steps:
    1. Traverse through each word.
    2. Sort the word to create the key.
    3. Store the original word in the hash map using the key.
    4. Finally, collect all the groups from the hash map.

------------------------------------------------------------------
Optimization:
- This solution sorts every string: O(K log K) where K = length of word.
- Alternative: Use a frequency count of 26 letters as key → O(K), faster for large inputs.

------------------------------------------------------------------
Time Complexity: O(N * K log K)
    N = number of strings
    K = maximum length of a string
    (Sorting each word and inserting into the map)

Space Complexity: O(N * K)
    Hash map stores all words grouped by their keys.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        // Step 1: Process each word
        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());   // sorted form as key
            mp[temp].push_back(strs[i]);      // insert original word into group
        }

        // Step 2: Collect groups
        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
