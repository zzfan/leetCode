/*************************************************************************
	> File Name: mergeKLists.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 16 Jul 2016 09:49:03 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* merge2Lists(ListNode* list1, ListNode* list2)
{
    //tmp必须分配空间
    ListNode* tmp = new ListNode(0);
    ListNode* head;
    head = tmp;
    while(list1&&list2){
        if(list1->val < list2->val){
            tmp->next = list1;
            list1 = list1->next;
            tmp = tmp->next;
        }
        else{
            tmp->next = list2;
            list2 = list2->next;
            tmp = tmp->next;
        }
    }
    if(list1) tmp->next = list1;
    if(list2) tmp->next = list2;
    return head->next;
}

//可以用二分法
ListNode* mergeKLists(vector<ListNode*> &lists)
{
    if(lists.size() == 0) return NULL;
    ListNode* res = NULL;
    res = lists[0];
    for(int i = 1; i<lists.size(); i++){
        res = merge2Lists(res, lists[i]);
    }
    return res;
}

