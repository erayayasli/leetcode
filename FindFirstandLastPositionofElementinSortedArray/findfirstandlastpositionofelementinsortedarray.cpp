// Source : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Date : 2025-12-11

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int firstFindLoc = -1;
        int secondFindLoc = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                firstFindLoc = i;
                break;
            }
        }
        if (firstFindLoc == -1)
            return { -1, -1 };

        for (int i = nums.size() - 1; i >= firstFindLoc; i--)
        {
            if (nums[i] == target)
            {
                secondFindLoc = i;
                break;
            }
        }
        return { firstFindLoc, secondFindLoc };
    }
};