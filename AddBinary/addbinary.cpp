// Source : https://leetcode.com/problems/add-binary/
// Date : 2025-12-17

/*
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    std::string addBinary(std::string a, std::string b)
    {
        // Make both strings the same length by padding with '0'
        if (a.size() > b.size())
        {
            while (a.size() != b.size())
                b.insert(b.begin(), '0');
        }
        else
        {
            while (a.size() != b.size())
                a.insert(a.begin(), '0');
        }

        int carry = 0;

        for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 2;
            a[i] = (sum % 2) + '0';
        }

        if (carry)
            a.insert(a.begin(), '1');

        return a;
    }
};
