// Source : https://leetcode.com/problems/majority-element
// Date : 2026-01-17

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than n / 2 times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
*/

class Solution {
public:
	int majorityElement(std::vector<int>& nums)
	{
		std::unordered_map<int, int>	occurrencesNumber;

		for (int i = 0; i < nums.size(); i++)
		{
			if (occurrencesNumber.find(nums[i]) == occurrencesNumber.end())
			{
				occurrencesNumber.insert({ nums[i], 1 });
			}
			else
			{
				occurrencesNumber[nums[i]] += 1;
			}
		}

		int majorityCount = nums.size() / 2;
		for (auto const& pair : occurrencesNumber)
		{
			if (pair.second > majorityCount)
			{
				return pair.first;
			}
		}
		return -1;
	}
};