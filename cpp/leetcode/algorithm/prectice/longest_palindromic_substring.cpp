/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
#include "pch.h"
#include<string> 
#include "minmax.h"
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() < 1) {
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++)
		{
			//一个元素为中心
			int len1 = expandAroundCenter(s, i, i);
			//两个元素为中心
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{   
			// 计算以left和right为中心的回文串长度
			L--;
			R++;
		}
		return R - L - 1;
	}
};