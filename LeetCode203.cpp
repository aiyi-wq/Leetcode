/*************************************************************************
	> File Name: LeetCode203.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:43:37 PM CST
 ************************************************************************/

struct ListCode* removeElements (struct ListNode* head, int val) {
    struct ListNode ret, *p = &ret, *q;
    ret.next = head;
    while (p && p->next) {
        if (p->next->val == val) {
            q = p->next;
            p->next = p->next->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return ret.next;
}
