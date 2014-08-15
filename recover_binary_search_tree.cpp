/************************************

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise
a constant space solution?

*************************************/

#include <cstring>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *swap1;
    TreeNode *swap2;

    TreeNode *last;
    int delta;

    void recoverTree(TreeNode *root) {
        swap1 = NULL;
        swap2 = NULL;
        last = NULL;
        delta = 0;

        traverse(root);

        if(swap2 == NULL){
            swap2 = last;
        }

        int temp = swap1->val;
        swap1->val = swap2->val;
        swap2->val = temp;
    }

    void traverse(TreeNode *root){
        if(root == NULL){
            return;
        }
        traverse(root->left);
        if(last != NULL){
            if(last->val > root->val){
                if(swap1 == NULL){
                    swap1 = last;
                    delta = last->val - root->val;
                }
                else{
                    if(swap2 == NULL){
                        swap2 = root;
                        return;
                    }
                }
            }
            else if(delta > 0 && delta < root->val - last->val){
                if(swap2 == NULL){
                    swap2 = last;
                    return;
                }
            }
        }
        last = root;
        traverse(root->right);
    }
};
