/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and
   ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.


    Example 1:

    Input: s = "()"
    Output: true
    Example 2:

    Input: s = "()[]{}"
    Output: true
    Example 3:

    Input: s = "(]"
    Output: false


    Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> umap;
        umap.insert({{')', '('}, {'}', '{'}, {']', '['}});

        std::stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == umap[c]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

// TC: O(n)
// SC: O(n)
