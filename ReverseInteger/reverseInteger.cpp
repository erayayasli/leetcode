// Source : https://leetcode.com/problems/reverse-integer/
// Date : 2025-11-07


/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1

*/

#include <exception>
#include <iostream>
#include <string>

class Solution {
    public:
        int reverse(int x) {
            std::string returnVal;

            std::string reversedForm = std::to_string(x);
            
            if(!reversedForm.empty() && reversedForm[0] == '-')
            {
                returnVal += '-';
                reversedForm.erase(0, 1);
            }
            for(std::size_t i = reversedForm.size(); i > 0; --i)
            {
                const std::size_t index = i - 1;
                returnVal += reversedForm[index];
            }

            try
            {
                const int convertedValue = std::stoi(returnVal);
                return convertedValue;
            }
            catch(const std::exception&)
            {
                return 0;
            }
        }
    };