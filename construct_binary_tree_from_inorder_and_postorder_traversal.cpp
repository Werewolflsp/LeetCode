/******************************************

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

*******************************************/

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, 0, 0, inorder.size());
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int instart,
                        int poststart, int length){
        if(length == 0){
            return NULL;
        }
        TreeNode *node = new TreeNode(postorder[poststart + length - 1]);
        for(int i = 0; i < length; i++){
            if(inorder[instart + i] == node->val){
                node->left = buildTree(inorder, postorder, instart, poststart, i);
                node->right = buildTree(inorder, postorder, instart + i + 1,
                                        poststart + i, length - i - 1);
                break;
            }
        }
        return node;
    }
};
