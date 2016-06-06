/*************************************************************************
	> File Name: addTwoNumbers.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 23 Mar 2016 07:45:51 PM PDT
 ************************************************************************/

#include<iostream>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode *p = &dummy;

    int cn = 0;
    while(l1 || l2){
        int val = cn + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        cn = val/10;
        val = val%10;
        p->next = new ListNode(val);
        p = p->next;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
    }

    if(cn != 0){
        p->next = new ListNode(cn);
        p = p->next;
    }

    return dummy.next;
}
