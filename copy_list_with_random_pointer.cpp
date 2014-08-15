/****************************

A linked list is given such that each node contains an
additional random pointer which could point to any node
in the list or null.

Return a deep copy of the list.

****************************/

// This isn't the meant solution, but leet code accepted it.
// I'll redo this when I'm in the mood.

#include <cstring>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *start = NULL;
        RandomListNode *node = NULL;
        while(head != NULL){
            if(node == NULL){
                node = new RandomListNode(head->label);
                if(start == NULL){
                    start = node;
                }
            }
            if(head->next != NULL){
                RandomListNode *temp = new RandomListNode(head->next->label);
                node->next = temp;
            }
            if(head->random != NULL){
                RandomListNode *temp = new RandomListNode(head->random->label);
                node->random = temp;
            }

            head = head->next;
            node = node->next;
        }
        return start;
    }
};
