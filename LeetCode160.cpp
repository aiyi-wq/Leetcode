/*************************************************************************
	> File Name: LeetCode160.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:36:25 PM CST
 ************************************************************************/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while (p != q) {
        p = p ? p->next : headB;
        q = q ? q->next : headA;
    }
    return p;
 }

