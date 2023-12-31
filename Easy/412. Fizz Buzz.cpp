/*
    Given an integer n, return a string array answer (1-indexed) where:

    answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
    answer[i] == "Fizz" if i is divisible by 3.
    answer[i] == "Buzz" if i is divisible by 5.
    answer[i] == i (as a string) if none of the above conditions are true.
     

    Example 1:

    Input: n = 3
    Output: ["1","2","Fizz"]

    Example 2:

    Input: n = 5
    Output: ["1","2","Fizz","4","Buzz"]

    Example 3:

    Input: n = 15
    Output:
   ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
     

    Constraints:

    1 <= n <= 104
*/

#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> ret;

        for (int i = 1; i < n + 1; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                ret.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                ret.push_back("Fizz");
            } else if (i % 5 == 0) {
                ret.push_back("Buzz");
            } else {
                ret.push_back(std::to_string(i));
            }
        }

        return ret;
    }
};

// TC: O(n)
// SC: O(1)
