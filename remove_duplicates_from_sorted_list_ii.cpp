/***********************************************

Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

***********************************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *iter = head;
        ListNode *ater = NULL;

        while(iter != NULL){
            while(iter->next != NULL && iter->next->val == iter->val){
                iter = iter->next;
            }
            if(ater == NULL && iter != head){
                head = iter->next;
            }
            else if(ater != NULL && ater->next != iter){
                ater->next = iter->next;
            }
            else{
                ater = iter;
            }
            iter = iter->next;
        }
        return head;
    }
};
