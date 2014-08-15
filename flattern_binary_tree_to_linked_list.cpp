/****************************************

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

****************************************/

#include <cstring>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL){
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *temp = root->left;
        TreeNode *last = NULL;
        while(temp!= NULL){
            last = temp;
            temp = temp->right;
        }
        if(last == NULL){
            return;
        }
        else{
            last->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
