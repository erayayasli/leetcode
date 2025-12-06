// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number
// Date : 2025-12-06

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {

        constexpr std::array<std::string_view, 10> equivalentsOfNumbers =
        { "", 
            ""    , "abc", "def", 
            "ghi" , "jkl", "mno", 
            "pqrs", "tuv", "wxyz"};
        
        std::vector<std::string_view> convertedVersionOfInput;
        for (int i = 0; i < digits.size(); i++)
        {
            convertedVersionOfInput.push_back(equivalentsOfNumbers[digits[i] - '0']);
        }

        std::vector<std::string> result = { "" }; 

        for (auto& letters : convertedVersionOfInput) 
        {
            std::vector<std::string> temp;

            for (auto& existing : result) {
                for (char c : letters) {
                    temp.push_back(existing + c);  
                }
            }
            result = std::move(temp); 
        }

        return result;
    }
};