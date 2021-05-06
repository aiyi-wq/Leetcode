/*************************************************************************
	> File Name: LeetCode19.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:16:39 PM CST
 *********************************************************************/


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = q = &ret;
    while (n--) { q = q->next; }
    q = q->next;
    while (q) {
        p = p->next;
        q = q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}
