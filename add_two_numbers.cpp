/**********************************

You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain
a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

**********************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = NULL;
        ListNode *iter = NULL;
        int step = 0;
        int sum;
        while(l1 != NULL && l2 != NULL){
            sum = l1->val + l2->val + step;
            step = sum / 10;
            sum = sum % 10;
            if(iter == NULL){
                res = new ListNode(sum);
                iter = res;
            }
            else{
                iter->next = new ListNode(sum);
                iter = iter->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *rest = l1 == NULL ? l2 : l1;
        while(rest != NULL){
            sum = step + rest->val;
            step = sum / 10;
            sum = sum % 10;
            if(iter == NULL){
                res = new ListNode(sum);
                iter = res;
            }
            else{
                iter->next = new ListNode(sum);
                iter = iter->next;
            }
            rest = rest->next;
        }
        if(step > 0){
            iter->next = new ListNode(step);
        }

        return res;
    }
};
