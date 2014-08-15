/****************************

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

****************************/

#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res;

    int maxPathSum(TreeNode *root) {
        res = INT_MIN;
        search(root);
        return res;
    }

    int search(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        else{
            int a = search(root->left);
            int b = search(root->right);
            if(root->left != NULL && a > res){
                res = a;
            }
            if(root->right != NULL && b > res){
                res = b;
            }
            int temp = max(a, 0) + max(b, 0) + root->val;
            if(temp > res){
                res = temp;
            }
            return max(max(a,b), 0) + root->val;
        }
    }
};
