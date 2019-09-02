/*
12. Integer to Roman

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, 
the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

#include "pch.h"
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		if (num == 0) {
			return "0";
		}

		string res;
		while (num) {
			if (num >= 1000) {
				res = res + "M";
				num -= 1000;
			}
			if (num < 1000 && num >= 900)
			{
				res = res + "CM";
				num -= 900;
			}
			if (num < 900 && num >= 500)
			{
				res = res + "D";
				num -= 500;
			}
			if (num < 500 && num >= 400)
			{
				res = res + "CD";
				num -= 400;
			}
			if (num < 400 && num >= 100)
			{
				res = res + "C";
				num -= 100;
			}
			if (num < 100 && num >= 90)
			{
				res = res + "XC";
				num -= 90;
			}
			if (num < 90 && num >= 50)
			{
				res = res + "L";
				num -= 50;
			}
			if (num < 50 && num >= 40)
			{
				res = res + "XL";
				num -= 40;
			}
			if (num < 40 && num >= 10)
			{
				res = res + "X";
				num -= 10;
			}
			if (num < 10 && num >= 9)
			{
				res = res + "IX";
				num -= 9;
			}
			if (num < 9 && num >= 5)
			{
				res = res + "V";
				num -= 5;
			}
			if (num < 5 && num >= 4)
			{
				res = res + "IV";
				num -= 4;
			}
			if (num < 4 && num >= 1)
			{
				res = res + "I";
				num -= 1;
			}
		}
		return res;
	}


	string intToRoman2(int num) {
		int values[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string reps[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		string res;
		for (int i = 0; i < 13; i++)
		{
			while (num >= values[i])
			{
				num -= values[i];
				res += reps[i];
			}
		}
		return res;
	}
};