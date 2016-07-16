/*************************************************************************
	> File Name: insertionSortList.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 16 Jul 2016 10:23:54 AM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

#define INT_MIN 0x80000000

ListNode* insertionSortList(ListNode* head)
{
    ListNode* newhead = new ListNode(INT_MIN);
    while(head){
        ListNode* cur = head;
        ListNode* p = newhead;
        while(p->next && p->next->val <= cur->val){
            p = p->next;
        }
        head = head->next;
        cur->next = p->next;
        p->next = cur;
    }
    head = newhead->next;
    delete newhead;
    return head;
}

