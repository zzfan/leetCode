/*************************************************************************
	> File Name: sortList.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 16 Jul 2016 10:41:14 AM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* mergeList(ListNode* p1, ListNode* p2)
{
    if(p1 == NULL){
        return p2;
    }else if(p2 == NULL){
        return p1;
    }else if(p1 == NULL && p2 == NULL){
        return NULL;
    }

    ListNode* newhead = new ListNode(0);
    ListNode* p = newhead;
    while(p1&&p2){
        if(p1->val > p2->val){
            p->next = p2;
            p2 = p2->next;
        }
        else{
            p->next = p1;
            p1 = p1->next;
        }
        p = p->next;
    }
    if(p1) p->next = p1;
    else if(p2) p->next = p2;
    return newhead->next;
}

//二分法加合并
ListNode* sortList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;

    ListNode* p1 = sortList(head);
    ListNode* p2 = sortList(fast);
    return mergeList(p1, p2);
}
