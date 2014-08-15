/************************************

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

************************************/

#include <cstring>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *last = NULL;

    // Traversal at inorder, and last node is less than current node(root)
    bool isValidBST(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        if(!isValidBST(root->left)){
            return false;
        }

        if(last != NULL){
            if(last->val >= root->val){
                return false;
            }
        }
        last = root;

        if(!isValidBST(root->right)){
            return false;
        }
        return true;
    }
};
