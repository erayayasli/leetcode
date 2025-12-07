// Source : https://leetcode.com/problems/valid-parentheses/
// Date : 2025-12-07

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

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

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(std::string s)
    {
        if (s.size() % 2 == 1)
            return false;

        std::stack<char> bracketStack;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                bracketStack.push(c);
            }
            else
            {
                if (bracketStack.empty())
                    return false;

                char top = bracketStack.top();
                if ((top == '(' && c == ')') ||
                    (top == '[' && c == ']') ||
                    (top == '{' && c == '}'))
                {
                    bracketStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return bracketStack.empty();
    }
};