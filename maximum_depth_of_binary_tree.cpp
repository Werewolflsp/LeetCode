/*************************************************

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the
root node down to the farthest leaf node.

*************************************************/

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

    int maxDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        res = INT_MIN;
        maxDepth(root, 0);
        return res;
    }

    void maxDepth(TreeNode *root, int length){
        if(root->left != NULL){
            maxDepth(root->left, length + 1);
        }
        if(root->right != NULL){
            maxDepth(root->right, length + 1);
        }
        if(root->left == NULL && root->right == NULL){
            res = max(res, length + 1);
        }
    }
};
