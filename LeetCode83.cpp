/*************************************************************************
	> File Name: LeetCode83.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:27:40 PM CST
 ************************************************************************/

struct ListNode* deleteDuplicate(struct ListNode* head) {
    struct ListNode *p = head, *q;
    while (p && p->next) {
        if (p->val - p->next->val) {
            p = p->next;
        }
        else {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head;
}
