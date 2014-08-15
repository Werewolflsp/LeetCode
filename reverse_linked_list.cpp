/*********************************

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

**********************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *rhead = NULL, *rtail = NULL, *rh_b = NULL, *rt_a = NULL;
        ListNode *iter, *ater, *eter;
        int i = 0;
        iter = head;
        while(iter != NULL){
            i++;
            if(i == m){
                rhead = iter;
                break;
            }
            else{
                rh_b = iter;
                iter = iter->next;
            }
        }

        ater = rh_b;
        eter = iter->next;

        while(iter != NULL){
            if(iter != rhead){
                iter->next = ater;
            }
            if(i == n){
                rtail = iter;
                rt_a = eter;
                break;
            }
            else{
                i++;
                ater = iter;
                iter = eter;
                if(eter != NULL){
                    eter = eter->next;
                }
            }
        }

        if(rh_b != NULL){
            rh_b->next = rtail;
        }
        rhead->next = rt_a;

        if(rhead == head){
            return rtail;
        }
        else{
            return head;
        }
    }
};
