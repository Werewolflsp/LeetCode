/*****************************************

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could
represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

*****************************************/

#include <cstring>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;

    int sumNumbers(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        search(root, 0);
        return res;
    }

    void search(TreeNode* root, int part){
        int num = 10*part + root->val;
        if(root->left == NULL && root->right == NULL){
            res += num;
            return;
        }
        if(root->left != NULL){
            search(root->left, num);
        }
        if(root->right != NULL){
            search(root->right, num);
        }
    }
};
