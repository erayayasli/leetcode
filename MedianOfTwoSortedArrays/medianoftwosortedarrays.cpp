// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Date : 2025-12-01

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::vector<int> mergedArray;

        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (i == nums1.size())
            {
                mergedArray.push_back(nums2[j]);
                j++;
                continue;
            }
            if (j == nums2.size())
            {
                mergedArray.push_back(nums1[i]);
                i++;
                continue;
            }

            if (nums1[i] == nums2[j])
            {
                mergedArray.push_back(nums1[i]);
                mergedArray.push_back(nums2[j]);
                i++;
                j++;
            }
            else if (nums1[i] >= nums2[j])
            {
                mergedArray.push_back(nums2[j]);
                j++;
            }
            else
            {
                mergedArray.push_back(nums1[i]);
                i++;
            }
        }

        int arraySize = mergedArray.size();
        if(arraySize % 2 == 0)
        {
            float medLeft = mergedArray[arraySize / 2];
            float medRight = mergedArray[(arraySize / 2) - 1];

            return (medLeft + medRight) / 2;            
        }
        else 
        {
            return mergedArray[arraySize / 2];
        }
    }
};