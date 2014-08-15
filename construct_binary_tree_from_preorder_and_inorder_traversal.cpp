/********************************************

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

********************************************/

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, 0, preorder.size());
    }

    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder, int prestart, int instart, int length){
        if(length == 0){
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[prestart]);
        for(int i = 0; i < length; i++){
            if(inorder[instart+i] == node->val){
                node->left = buildTree(preorder, inorder, prestart + 1, instart, i);
                node->right = buildTree(preorder, inorder, prestart + i + 1, instart + i + 1, length - i - 1);
                break;
            }
        }
        return node;
    }
};
