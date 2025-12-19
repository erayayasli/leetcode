// Source : https://leetcode.com/problems/sort-colors/
// Date : 2025-12-19

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/

class Solution {
public:
    void sortColors(std::vector<int>& nums) 
    {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeroCount++;
            else if (nums[i] == 1)
                oneCount++;
            else if (nums[i] == 2)
                twoCount++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (zeroCount)
            {
                nums[i] = 0;
                zeroCount--;
            }
            else if (oneCount)
            {
                nums[i] = 1;
                oneCount--;
            }
            else if (twoCount)
            {
                nums[i] = 2;
                twoCount--;
            }
        }
    }

    void print(std::vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
            std::cout << nums[i];
    }
};