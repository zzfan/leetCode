/*************************************************************************
	> File Name: oddEvenList.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 10 Jun 2016 10:41:23 AM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *temp;
    ListNode* odd = head;
    ListNode* even = head->next;
    temp = even;
    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
    	even = even->next;
    }
    odd->next = temp;
    return head;
}
