// Source : https://leetcode.com/problems/two-sum/
// Date : 2025-09-15

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <unordered_map>
#include <string>
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> numbertoIndex;
         for(int i = 0; i < nums.size(); i++)
         {
             int currentTarget = target - nums[i];
             if (numbertoIndex.find(currentTarget) != numbertoIndex.end())
             {
                 return  std::vector<int>{numbertoIndex[currentTarget], i};
             }
             numbertoIndex[nums[i]]= i;
         }
        return std::vector<int>{};
    }
};