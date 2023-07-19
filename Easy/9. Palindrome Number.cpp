/*
    Given an integer x, return true if x is a palindrome, and false otherwise.


    Example 1:

    Input: x = 121
    Output: true
    Explanation: 121 reads as 121 from left to right and from right to left.

    Example 2:

    Input: x = -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it
   becomes 121-. Therefore it is not a palindrome. Example 3:

    Input: x = 10
    Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
     

    Constraints:

    -231 <= x <= 231 - 1
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        if (x % 10 == 0)
            return false;

        int revert_num = 0;
        while (x > revert_num) {
            revert_num =
                revert_num * 10 +
                x % 10;  // Put current last number in x into revert_num.
            x /= 10;     // Remove last number of x.
        }

        return x == revert_num || x == revert_num / 10;
    }
};

// Get last number: x % 10.
// Remove last number: x / 10.

// TC: O(n)
// SC: O(1)
