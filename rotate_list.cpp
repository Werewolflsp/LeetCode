/****************************************

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

****************************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *iter = head;
        int n = 0;
        while(iter != NULL){
            n++;
            iter = iter->next;
        }

        if(n == 0){
            return head;
        }

        k = k % n;
        if(k == 0){
            return head;
        }

        int i = 1;
        iter = head;

        while(i < n-k){
            i++;
            iter = iter->next;
        }

        ListNode *ater = iter->next;
        iter->next = NULL;
        iter = ater;
        while(ater->next != NULL){
            ater = ater->next;
        }
        ater->next = head;
        return iter;
    }
};
