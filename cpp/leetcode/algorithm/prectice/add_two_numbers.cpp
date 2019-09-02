/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


*/

#include "pch.h" 
#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 struct ListNode *node = new struct ListNode(0);
		 struct ListNode *p = l1, *q = l2, *root = node;
		 //进位
		 int carry = 0;

		 while (p != NULL || q != NULL)
		 {
			 int x = (p == NULL) ? 0 : p->val;
			 int y = (q == NULL) ? 0 : q->val;
			 int result = x + y + carry;
			 carry = result / 10;
			 //设置下一个节点
			 node->next = new struct ListNode(result % 10);
			 //指针移到下一位
			 node = node->next;

			 if (p != NULL) p = p->next;
			 if (q != NULL) q = q->next;
		 }
		 if (carry > 0)
			 node->next = new struct ListNode(carry);
		 return root->next;
	}



