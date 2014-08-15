/**************************************

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

***************************************/

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        else{
            res = inorderTraversal(root->left);
            res.push_back(root->val);
            vector<int> a = inorderTraversal(root->right);
            res.insert(res.end(), a.begin(), a.end());
        }
        return res;
    }
};
