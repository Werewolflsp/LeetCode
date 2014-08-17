/***********************************

Merge two sorted linked lists and return it as a new list. The new list should
be made by splicing together the nodes of the first two lists.

***********************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL){
            return l2;
        }
        else if (l2 == NULL){
            return l1;
        }
        else{
            if(l1->val < l2->val){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
};