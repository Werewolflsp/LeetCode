/******************************************

Sort a linked list in O(n log n) time using constant space complexity.

******************************************/

#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int count = 0;
        ListNode* iter = head;
        while(iter != NULL){
            iter = iter->next;
            count++;
        }
        return merge(head, count);
    }

    ListNode *merge(ListNode *head, int count){
        if(count == 0 || count == 1){
            return head;
        }

        ListNode *iter = head;
        int a_count = 0;
        while(a_count < (count / 2 - 1)){
            iter = iter->next;
            a_count++;
        }
        ListNode *B_head = iter->next;
        iter->next = NULL;

        ListNode *A = merge(head, count/2);
        ListNode *B = merge(B_head, count - count/2);

        iter = NULL;
        while(A != NULL && B != NULL){
            if(A->val <= B->val){
                if(iter == NULL){
                    iter = A;
                    head = A;
                }
                else{
                    iter->next = A;
                    iter = A;
                }
                A = A->next;
            }
            else{
                if(iter == NULL){
                    iter = B;
                    head = B;
                }
                else{
                    iter->next = B;
                    iter = B;
                }
                B = B->next;
            }
        }
        if(A != NULL){
            iter->next = A;
        }
        else{
            iter->next = B;
        }
        return head;
    }
};
