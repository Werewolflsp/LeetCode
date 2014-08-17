/**********************************

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the
values in the list, only nodes itself can be changed.

*********************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *a = head;
        ListNode *b = NULL;
        ListNode *c;
        int k = 2;
        int interval = 0;
        while(a != NULL){
            interval++;
            c = a->next;
            if(interval == k){
                if(b == NULL){
                    head = reverse(head, k);
                }
                else{
                    b->next = reverse(b->next, k);
                }
                for(int i = 0; i < k; i++){
                    if(b == NULL){
                        b = head;
                    }
                    else{
                        b = b->next;
                    }
                }
                interval = 0;
            }
            a = c;
        }
        return head;
    }

    ListNode *reverse(ListNode *head, int k){
        ListNode *iter = head;
        ListNode *saveHead = head;
        ListNode *ater = NULL;
        ListNode *eter;
        int count = 0;
        while(iter != NULL && count < k){
            count++;
            eter = iter->next;
            iter->next = ater;
            ater = iter;
            iter = eter;
            head = ater;
        }
        if(saveHead != NULL){
            saveHead->next = eter;
        }
        return head;
    }
};
