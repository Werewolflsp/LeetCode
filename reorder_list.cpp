/**************************

Given a singly linked list L: L0->→L1->→…→Ln-1->→Ln,
reorder it to: L0->→Ln->→L1->→Ln-1->→L2->→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

**************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL){
            return;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        //fast is the head of the second half
        ListNode *third = NULL;
        slow = NULL;
        if(fast != NULL && fast->next != NULL){
            slow = fast->next;
            third = slow->next;
            fast->next = NULL;
        }

        while(fast != NULL && slow != NULL && third != NULL){
            slow->next = fast;
            fast = slow;
            slow = third;
            third = third->next;
        }

        if(fast != NULL && slow != NULL && third == NULL){
            slow->next = fast;
            fast = slow;
        }

        slow = head;
        third = fast;
        while(slow != NULL && fast != NULL){
            third = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            fast = third;

            slow = slow->next->next;
        }
    }
};
