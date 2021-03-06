
/*
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include "pch.h"
#include <iostream>
#include<vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

	int i, sum;
	vector<int> results;
	map<int, int> hashMap;
	for (i = 0; i < nums.size(); i++) {
		// IF NOT EXIST  Keys must be unique in map, so duplicates are ignored
		if (!hashMap.count(nums[i])) {
			hashMap.insert(pair<int, int>(nums[i], i));
		}
		if (hashMap.count(target - nums[i])) {
			int j = hashMap[target - nums[i]];
			if (j < i) {
				results.push_back(j);
				results.push_back(i);
			}
			else if(i>j){
				results.push_back(i);
				results.push_back(j);
			}
		}

	}
	return results;
}

vector<int> twoSumSimple(vector<int>& nums, int target) {
	vector<int> results;
	int i, j;
	for (i = 0; i < nums.size(); i++) {
		for (j = 0; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target) {
				if (j < i) {
					results.push_back(j);
					results.push_back(i);
				}
				else if (i > j) {
					results.push_back(i);
					results.push_back(j);
				}
			}
		}
	}
	return results;
}


int main()
{
	static vector<int> a = {1,2,3,4,5,6,7};
	static int b = 8;
	vector<int> res = twoSumSimple(a, b);
	std::cout << res[0];
	std::cout << res[1];
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


// twoSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
