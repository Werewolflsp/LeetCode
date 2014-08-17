/**********************************

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

**********************************/

#include <cstring>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *iter = head;
        vector<ListNode*> record;
        while(iter != NULL){
            record.push_back(iter);
            iter = iter->next;
        }
        if(n == record.size()){
            return head->next;
        }
        else{
            record[record.size()-n-1]->next = record[record.size()-n]->next;
            return head;
        }
    }
};
