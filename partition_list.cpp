/*******************************************

Given a linked list and a value x, partition it such that all nodes less than x come
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

********************************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *iter = head;
        ListNode *ater = NULL;
        ListNode *insert = NULL;
        while(iter != NULL){
            if(iter->val < x){
                if(insert != ater){
                    ater->next = iter->next;
                    if(insert != NULL){
                        iter->next = insert->next;
                        insert->next = iter;
                    }
                    else{
                        iter->next = head;
                        head = iter;
                    }
                    insert = iter;
                    iter = ater->next;
                }
                else{
                    insert = iter;
                    ater = iter;
                    iter = iter->next;
                }
            }
            else {
                ater = iter;
                iter = iter->next;
            }
        }
        return head;
    }
};
