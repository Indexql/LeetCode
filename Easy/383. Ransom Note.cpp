/*
    Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

    Each letter in magazine can only be used once in ransomNote.

     
    Example 1:

    Input: ransomNote = "a", magazine = "b"
    Output: false
    
    Example 2:

    Input: ransomNote = "aa", magazine = "ab"
    Output: false
    
    Example 3:

    Input: ransomNote = "aa", magazine = "aab"
    Output: true
     

    Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.
*/

#include <iostream>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        int hash[26] = {0};
        
        for (auto ch : magazine) {
            ++hash[ch - 'a'];
        }

        for (auto ch : ransomNote) {
            if (!hash[ch - 'a']--) return false;
        }

        return true;
    }
};

// TC: O(n)
// SC: O(1)
