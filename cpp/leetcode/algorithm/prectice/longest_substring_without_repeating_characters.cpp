/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include "pch.h"
#include<string>
#include <unordered_set>
#include "minmax.h"
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) {
			return 0;
		}
		unordered_set<char> lookup;
		int maxStr = 0;
		int left = 0;
		for (int i = 0; i < s.size(); i++) {
			while (lookup.find(s[i]) != lookup.end()){
				lookup.erase(s[left]);
			    left++;
		}
		maxStr = max(maxStr, i - left + 1);
		lookup.insert(s[i]);
	}
	return maxStr;
}
};