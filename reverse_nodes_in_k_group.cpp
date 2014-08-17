/**********************************

Given a linked list, reverse the nodes of a linked list k at a time and return
its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end
should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

***********************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *a = head;
        ListNode *b = NULL;
        ListNode *c;
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
