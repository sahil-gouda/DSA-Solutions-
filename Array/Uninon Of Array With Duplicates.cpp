// Problem: Union of Arrays with Duplicates
// Platform: GeeksforGeeks
// Author: Sahil Gouda

/*
Problem Statement:
You are given two arrays a[] and b[]. 
Return the Union of both arrays in any order.

The Union of two arrays is a collection of all distinct elements 
present in either of the arrays. 
If an element appears more than once in one or both arrays, 
it should be included only once in the result.

Note:
- Elements of a[] and b[] are not necessarily distinct.
- You can return the union in any order (driver code will print it sorted).

------------------------------------------------------------------
Example:
Input:  a[] = [1, 2, 3, 2, 1]
        b[] = [3, 2, 2, 3, 3, 2]
Output: [1, 2, 3]

Explanation:
The union set of both arrays is {1, 2, 3}.

------------------------------------------------------------------
Approach:
- Use an unordered_map to store unique elements from both arrays.
- Insert every element of a[] and b[] into the map.
- Extract the keys (unique numbers) into a vector.
- Sort the vector before returning (since unordered_map is unsorted).

------------------------------------------------------------------
Optimization:
- Instead of unordered_map, unordered_set can be used for cleaner code.
- unordered_set automatically stores unique elements.

------------------------------------------------------------------
Time Complexity: O((n + m) + k log k)
    → O(n + m) for insertion
    → O(k log k) for sorting the unique elements
Space Complexity: O(k)   (for unique elements)
*/

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> mp;  // stores unique elements as keys

        // Insert elements from the first array
        for (int i = 0; i < a.size(); i++) {
            mp[a[i]]++;  // increment count (or create new key)
        }

        // Insert elements from the second array
        for (int i = 0; i < b.size(); i++) {
            mp[b[i]]++;
        }

        // Collect all unique keys
        vector<int> result;
        for (auto& it : mp) {
            result.push_back(it.first);
        }

        // Sort since unordered_map doesn’t maintain order
        sort(result.begin(), result.end());

        return result;
    }
};
