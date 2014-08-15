/****************************************

Given an array where elements are sorted in ascending order,
convert it to a height balanced BST.

****************************************/

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size());
    }

    TreeNode *sortedArrayToBST(vector<int> &num, int start, int size){
        if(size == 0){
            return NULL;
        }
        TreeNode *node = new TreeNode(num[start + size / 2]);
        node->left = sortedArrayToBST(num, start, size / 2);
        node->right = sortedArrayToBST(num, start + size / 2 + 1, size - size / 2 - 1);
        return node;
    }
};
