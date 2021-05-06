/*************************************************************************
	> File Name: LeetCode141.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:32:47 PM CST
 ************************************************************************/
 //快慢指针：p每次走一步，q每次走两步
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if (p == NULL) return NULL;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return NULL;
        q = q->next;
    } while (p != q);
    q = head;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
 }
