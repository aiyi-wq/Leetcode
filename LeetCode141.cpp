/*************************************************************************
	> File Name: LeetCode141.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jun 2020 04:32:47 PM CST
 ************************************************************************/
 //快慢指针：p每次走一步，q每次走两步
bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if (p == NULL) return false;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return false;
        q = q->next;
    } while (p != q);
    return true;
 }
