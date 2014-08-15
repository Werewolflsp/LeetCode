/***************************************

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

***************************************/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> res;

    vector<int> postorderTraversal(TreeNode *root) {
        res.clear();
        Traversal(root);
        return res;
    }

    void Traversal(TreeNode *root){
        if(root == NULL){
            return;
        }
        Traversal(root->left);
        Traversal(root->right);
        res.push_back(root->val);
    }
};
