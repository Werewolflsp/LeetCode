/******************************

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

******************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *h = head;
        while(head != NULL){
            if((long long)(head->next) % 2 == 1){
                while((long long)(h->next) % 2 == 1){
                    h->next = (ListNode *)((long long)(h->next) - 1);
                    h = h->next;
                }
                return true;
            }
            else{
                long long temp = (long long)(head->next);
                head->next = (ListNode *)(temp + 1);
                head = (ListNode *)temp;
            }
        }

        return false;
    }
};
