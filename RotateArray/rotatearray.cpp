// Source : https://leetcode.com/problems/rotate-array
// Date : 2026-01-17
/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

class Solution {
public:
    void rotate(std::vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        if (n <= 1) return;

        k %= n;
        if (k == 0) return;

        // save last k
        std::vector<int> temp(k);
        int start = n - k;
        for (int i = 0; i < k; ++i)
            temp[i] = nums[start + i];

        // shift right by k 
        for (int i = n - k - 1; i >= 0; --i)
            nums[i + k] = nums[i];

        // put saved at beginning
        for (int i = 0; i < k; ++i)
            nums[i] = temp[i];
    }
};