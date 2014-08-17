/**********************************

Merge k sorted linked lists and return it as one sorted list. Analyze and
describe its complexity.

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0){
            return NULL;
        }
        else if(lists.size() == 1){
            return lists.front();
        }
        else{
            vector<ListNode *> temp;
            int i = 0;
            for(; i < lists.size() - 1; i += 2){
                temp.push_back(mergeTwoLists(lists[i], lists[i+1]));
            }
            if(i == lists.size() - 1){
                temp.push_back(lists[i]);
            }
            return mergeKLists(temp);
        }
    }

    ListNode *mergeTwoLists(ListNode *a, ListNode *b){
        ListNode *head;
        ListNode *pre = NULL;
        ListNode *next;
        while(a != NULL && b != NULL){
            if(a->val < b->val){
                next = a;
                a = a->next;
            }
            else{
                next = b;
                b = b->next;
            }
            if(pre == NULL){
                pre = next;
                head = pre;
            }
            else{
                pre->next = next;
                pre = next;
            }
        }
        if(a != NULL){
            next = a;
        }
        else{
            next = b;
        }
        if(pre == NULL){
            head = next;
        }
        else{
            pre->next = next;
        }

        return head;
    }
};
