// Source : https://leetcode.com/problems/zigzag-conversion
// Date : 2025-12-01
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
*/

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size())
            return s;

        std::vector<std::string> rows(numRows);

        int row = 0, direction = 1; // 1 Down, 0 Up
        for (char ch : s)
        {             
            if (direction)
            {
                rows[row] += ch;

                if (row == 0)
                    direction = 1;               // we are at the top -> down
                else if (row == numRows - 1)
                    direction = -1;              // we are at the bottom -> up

                row += direction;
            }
        }

        std::string returnval;
        returnval.reserve(s.size());
        for (const std::string& a : rows)
        {
            returnval += a;
        }

        return returnval;
    }
};
