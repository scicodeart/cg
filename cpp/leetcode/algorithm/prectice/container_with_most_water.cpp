/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/
#include "pch.h"
#include<vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int MaxPool = 0;
		int j = height.size() - 1;
		int i = 0;
		for (; i < j;)
		{
			if (height[i] <= height[j])
			{
				MaxPool = MaxPool > height[i] * (j - i) ? MaxPool : height[i] * (j - i);
				++i;
			}
			if (height[i] > height[j])
			{
				MaxPool = MaxPool > height[j] * (j - i) ? MaxPool : height[j] * (j - i);
				--j;
			}

		}
		return MaxPool;

	}
};