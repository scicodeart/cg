/*
8. String to Integer (atoi)

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
			 Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
			 digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
			 Thefore INT_MIN (−231) is returned.
*/

#include "pch.h"
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (isalpha(str[0])) return 0;
		long long  ans = 0;
		int flag = 0;// 出现 '-' 置1 
		int len = 0;//记录数字的长度   
		int temp = 0;//记录 "+-" 出现的次数 
		for (char c : str) {
			//判断 正负号   且数字长度为0  防止 "0-1" 这样的情况 
			if ((c == '+' || c == '-') && len == 0) {
				//记录符号出现次数 
				temp++;			
				flag = (c == '-') ? 1 : 0;
			}
			else if (0 <= (c - '0') && (c - '0') <= 9 && temp < 2) { 		//temp<2 表示 正负号 只出现过一次 
				ans = ans * 10 + (c - '0');
				len++;
				// INT_MAX=2147483647 	INT_MIN=-2147483648   
				// 如果 数字的绝对值 大于 INT_MAX +1 那么直接跳出 一定溢出 
				if (ans - 1 > INT_MAX) break;		
			}
			//如果是空格则继续 但前提是 之前没有出现过 正负号 和 数字
			else if (c == ' ' && len == 0 && temp == 0)		 
				continue;
			//其他情况：英文和其他字符 
			else		
				break;
		}
		//flag==1 表示数字为负
		if (flag == 1)			 
			return -ans < INT_MIN ? INT_MIN : -ans;
		return ans > INT_MAX ? INT_MAX : ans;
	}
};