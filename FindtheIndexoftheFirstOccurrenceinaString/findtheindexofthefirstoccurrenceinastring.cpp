// Source : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Date : 2025-12-20

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

class Solution {
public:
    int strStr(std::string haystack, std::string needle) 
    {
        if (needle.empty()) return -1;
        if (needle.size() > haystack.size()) return -1;

        for (int i = 0; i <= haystack.size()- needle.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                int flag = true;
                for (int j = 1; j < needle.size(); j++)
                {
                    if (!(haystack[i + j] == needle[j]))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                    return i;
            }
        }
        return -1;
    }
};