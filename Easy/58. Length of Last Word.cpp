/*
    Given a string s consisting of words and spaces, return the length of the
    last word in the string.

    A word is a maximal substring consisting of non-space characters only.

     
    Example 1:

    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.

    Example 2:

    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.

    Example 3:

    Input: s = "luffy is still joyboy"
    Output: 6
    Explanation: The last word is "joyboy" with length 6.
     

    Constraints:

    1 <= s.length <= 104
    s consists of only English letters and spaces ' '.
    There will be at least one word in s.
*/

// #include <string>

// class Solution {
// public:
//     int lengthOfLastWord(std::string s) {
//         int i = s.size() - 1;
//         int count = 0;
        
//         // Ignore spaces in the end.
//         while (i >= 0 && s[i] == ' ') {
//             --i;
//         }

//         // Count the length of last word.
//         while (i >= 0 && s[i] != ' ') {
//             ++count;
//             --i;
//         }

//         return count;
//     }
// };

#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::string::reverse_iterator rit = s.rbegin();
        int count = 0;
        
        // Ignore spaces in the end.
        while (rit != s.rend() && *rit == ' ') {
            ++rit;
        }

        // Count the length of last word.
        while (rit != s.rend() && *rit != ' ') {
            ++count;
            ++rit;
        }

        return count;
    }
};

// TC: O(n)
// SC: O(1)
