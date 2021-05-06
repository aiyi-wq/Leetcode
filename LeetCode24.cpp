/*************************************************************************
	> File Name: LeetCode24.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:21:07 PM CST
 ************************************************************************/

/**
 * Definition for singly_linked list.
 * struct ListNode {
 *      int val;
 *      struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *q, ret;
    ret.next = head;
    p = &ret;
    q = head;
    while (q && q->next) {
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }
    return ret.next;
}
