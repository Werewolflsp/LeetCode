/**************************************************************************

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
Have you been asked this question in an interview?

**************************************************************************/

#include <cstring>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return;
        }
        vector<TreeLinkNode *> v[2];
        int c = 0;
        int p = 1;
        v[p].push_back(root);

        while(v[p].size() != 0){
            for(auto it = v[p].begin(); it != v[p].end(); it++){
                if(it+1 != v[p].end()){
                    (*it)->next = *(it+1);
                }
                else{
                    (*it)->next = NULL;
                }
                if((*it)->left != NULL){
                    v[c].push_back((*it)->left);
                }
                if((*it)->right != NULL){
                    v[c].push_back((*it)->right);
                }
            }

            v[p].clear();
            p = !p;
            c = !c;
        }
    }
};
