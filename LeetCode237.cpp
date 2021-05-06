/*************************************************************************
	> File Name: LeetCode237.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Jun 2020 08:26:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void deleteNode(struct ListNode* node) {
    struct ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    free(p);
    return ;
}
