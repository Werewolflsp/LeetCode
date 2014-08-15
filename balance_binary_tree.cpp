/****************************************

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of every node never differ by more than 1.

****************************************/

#include <cstring>
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
    bool isBalanced(TreeNode *root) {
        return Depth(root) >= 0;
    }

    int Depth(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int a = Depth(root->left);
        if(a == -1){
            return -1;
        }
        int b = Depth(root->right);
        if(b == -1){
            return -1;
        }

        int a1 = max(a, b);
        int b1 = min(a, b);

        if(a1 - b1 <= 1){
            return a1+1;
        }
        else{
            return -1;
        }
    }
};
