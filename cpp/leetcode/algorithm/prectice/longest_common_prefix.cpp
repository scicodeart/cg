/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/
#include "pch.h"
#include<vector>
#include "minmax.h"
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		int min1 = INT_MAX;
		string a;

		for (int i = 0; i < strs.size(); i++)
		{
			int m = strs[i].size();
			min1 = min(min1, m);
		}
		for (int i = 0; i < min1; i++) {
			for (int k = 0; k < strs.size() - 1; k++)
			{
				if (strs[k][i] == strs[k + 1][i])
					continue;
				else return a;
			}
			a = a + strs[0][i];
		}
		return a;
	}
};


