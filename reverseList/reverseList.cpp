/*************************************************************************
	> File Name: reverseList.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 10 Jun 2016 05:31:03 PM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {  
    if(head == NULL || head->next == NULL)  
        return head;  
    ListNode result(0);  
    ListNode *p = head;  
    while (p) {  
        ListNode *q = p->next;  
        p->next = result.next;  
        result.next = p;  
        p = q;  
    }  
    return result.next;  
}  
