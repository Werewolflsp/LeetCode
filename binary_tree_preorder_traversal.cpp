/********************************

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

********************************/

#include <cstring>
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

    vector<int> preorderTraversal(TreeNode *root) {
        res.clear();
        Traversal(root);
        return res;
    }

    void Traversal(TreeNode *root){
        if(root == NULL){
            return;
        }
        res.push_back(root->val);
        Traversal(root->left);
        Traversal(root->right);
    }
};
