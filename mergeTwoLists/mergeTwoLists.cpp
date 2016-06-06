/*************************************************************************
	> File Name: mergeTwoLists.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 06 Apr 2016 02:07:04 PM HKT
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x); val(x), next(NULL){}
};

ListNode *mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *l3;
    ListNode *temp;
    l3 = temp;
    while(l1 && l2){
        if(l1->val > l2->val){
            temp->next = l2;
            l2 = l2->next;
        }
        else{
            temp->next = l1;
            l1 = l1->next;
        }
        temp = temp->next;
    }
    if(l1 != NULL)
    temp->next = l1;
    else
    temp->next = l2;
    return l3->next;
}

