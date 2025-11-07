// Source : https://leetcode.com/problems/longest-common-prefix/
// Date : 2025-11-07

/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
 */

#include <string>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        std::string longestPrefix;

        for (const std::string& word : strs)
        {
            if (word.empty())
            {
                return "";
            }

            if (longestPrefix.empty())
            {
                longestPrefix = word;
                continue;
            }

            std::string commonPrefixCandidate;
            bool hasCommonCharacter = false;

            for (std::size_t i = 0; i < word.size() && i < longestPrefix.size(); ++i)
            {
                if (longestPrefix[i] == word[i])
                {
                    commonPrefixCandidate += word[i];
                    hasCommonCharacter = true;
                }
                else
                {
                    longestPrefix = commonPrefixCandidate;
                    if (!hasCommonCharacter)
                    {
                        return "";
                    }
                    break;
                }
            }

            longestPrefix = commonPrefixCandidate;
        }

        return longestPrefix;
    }
};