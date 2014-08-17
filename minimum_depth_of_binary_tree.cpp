/**************************************

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root
node down to the nearest leaf node.

**************************************/

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

    int minDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        res = INT_MAX;
        minDepth(root, 0);
        return res;
    }

    void minDepth(TreeNode *root, int length){
        if(root->left != NULL){
            minDepth(root->left, length + 1);
        }
        if(root->right != NULL){
            minDepth(root->right, length + 1);
        }
        if(root->left == NULL && root->right == NULL){
            res = min(res, length + 1);
        }
    }
};
