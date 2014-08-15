/************************************************

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

************************************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ater = NULL;
        ListNode *iter = head;
        while(iter != NULL){
            if(ater == NULL || ater->val != iter->val){
                ater = iter;
                iter = iter->next;
            }
            else{
                ater->next = iter->next;
                iter = iter->next;
            }
        }
        return head;
    }
};
