/******************************

Sort a linked list using insertion sort.

******************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *unsorted = head->next;
        head->next = NULL;
        while(unsorted != NULL){
            ListNode *temp;
            if(unsorted->val <= head->val){
                temp = unsorted->next;
                unsorted->next = head;
                head = unsorted;
                unsorted = temp;
                continue;
            }
            ListNode *iter = head->next;
            ListNode *ater = head;
            while(iter != NULL){
                if(unsorted->val <= iter->val){
                    temp = unsorted->next;
                    unsorted->next = iter;
                    ater->next = unsorted;
                    ater = ater->next;
                    unsorted = temp;
                    break;
                }
                else{
                    iter = iter->next;
                    ater = ater->next;
                }
            }
            if(iter == NULL){
                ater->next = unsorted;
                unsorted = unsorted->next;
                ater->next->next = NULL;
            }
        }
        return head;
    }
};
