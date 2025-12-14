// Source : https://leetcode.com/problems/trapping-rain-water
// Date : 2025-12-14

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

class Solution {
public:
    int trap(std::vector<int>& height)
    {
        const int n = static_cast<int>(height.size());
        if (n < 3) return 0;

        int totalWater = 0;

        // left -> right, only count valleys that get closed (right >= left)
        int leftWallHeight = 0;
        int innerWidth = 0;
        int innerHeightSum = 0;

        int lastClosedIndex = 0; // after this index, we might have an "open" valley

        leftWallHeight = height[0];
        for (int i = 1; i < n; ++i)
        {
            if (height[i] >= leftWallHeight)
            {
                // Valley closed
                totalWater += leftWallHeight * innerWidth - innerHeightSum;

                // Reset with new left wall
                leftWallHeight = height[i];
                innerWidth = 0;
                innerHeightSum = 0;

                lastClosedIndex = i;
            }
            else
            {
                innerWidth++;
                innerHeightSum += height[i];
            }
        }

        // If we closed everything, we are done.
        // Otherwise, handle the remaining open part by scanning from the right.
        if (lastClosedIndex < n - 1)
        {
            //right -> left, symmetric logic on the remaining suffix
            int rightWallHeight = height[n - 1];
            innerWidth = 0;
            innerHeightSum = 0;

            for (int i = n - 2; i >= lastClosedIndex; --i)
            {
                if (height[i] >= rightWallHeight)
                {
                    totalWater += rightWallHeight * innerWidth - innerHeightSum;

                    rightWallHeight = height[i];
                    innerWidth = 0;
                    innerHeightSum = 0;
                }
                else
                {
                    innerWidth++;
                    innerHeightSum += height[i];
                }
            }
        }

        return totalWater;
    }
};