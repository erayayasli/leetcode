// Source : https://leetcode.com/problems/longest-valid-parentheses/
// Date : 2025-12-08

/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> paranthesesIndex;
        paranthesesIndex.push(-1);

        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                paranthesesIndex.push(i);
            }
            else if (s[i] == ')')
            {
                if (!paranthesesIndex.empty())
                {
                    paranthesesIndex.pop();

                    if (paranthesesIndex.empty())
                    {
                        paranthesesIndex.push(i);
                    }
                    else {
                        maxLen = std::max(maxLen, i - paranthesesIndex.top());
                    }
                }
            }
        }
        return maxLen;
    }
};
