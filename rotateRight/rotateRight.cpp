/*************************************************************************
	> File Name: rotateRight.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 27 Apr 2016 08:19:06 PM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* rotateRight(ListNode* head, int k)
{
    if(head == NULL) return head;
    int offset = k, len = 0;
    ListNode *hd = head, *flag, *result;
    for( ListNode *node = head; node != NULL; node = node->next ){
        len++;
    }
    offset = k%len;
    while(hd->next != NULL){
        offset--;
        if(offset == 0){
            flag = head;
        }
        else if(offset < 0){
            flag = flag->next;
        }
        hd = hd->next;
    }
    if(offset > 0) return head;
    else{
        result = flag->next;
        hd->next = head;
        flag->next = NULL;
    }
    return result;
}

ListNode* rorateRight(ListNode* head, int k)
{
    if(head == NULL || k ==0) return head;  
    int len =1;  
    ListNode* p = head,*pre;  
    while(p->next!=NULL)  
    {  
      p = p->next;  
       len++;      
    }  
    k = len-k%len;  
    p->next = head;  
    int step =0;  
    while(step< k)  
    {  
       p = p->next;  
       step++;  
    }  
    head = p->next;  
    p->next = NULL;  
    return head;  
}
