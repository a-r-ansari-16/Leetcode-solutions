// Problem: Isomorphic Strings (LeetCode 205)
// Status: Solved (after understanding teacher's explanation)

// Approach
// Check if both strings have the same length. If not, return false.
// Maintain a mapping from characters of s to t.
// Also maintain the reverse mapping from t to s.
// While traversing both strings:
// If a character has not been mapped yet, create the mapping.
// Otherwise, verify that the existing mapping matches the current character.
// If any mapping conflicts, return false.
// If the traversal finishes without conflicts, return true.

// Time Complexity: O(n)
// Space Complexity: O(1) (constant size alphabet)

// What I Learned
// A one-to-one mapping must exist in both directions.
// Using two mappings (or two arrays/vectors) avoids duplicate mappings.
// This is a hashing/mapping pattern that appears in many string problems.

// Difficulty
// ⭐⭐⭐⭐☆ (4/5)

// My Mistake
// I couldn't identify that this was a character-mapping problem.
// I was trying to compare characters directly instead of maintaining relationships between them

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> v(500,1000);
        for(int i = 0; i < s.length(); i++){
            int idx = (int)s[i];
            if(v[idx] == 1000)
                v[idx] = s[i] - t[i];
            else if(v[idx] != s[i] - t[i]) return false;
        }
        // refill the vector with 1000 again
        for(int i  = 0; i < 150; i++){
            v[i] = 1000;
        }
        for(int i = 0; i < s.length(); i++){
            int idx = (int)t[i];
            if(v[idx] == 1000)
                v[idx] = t[i] - s[i];
            else if(v[idx] != t[i] - s[i]) return false;
        }
        return true;
    }
};