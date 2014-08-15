/***************************************

Given a binary tree and a sum, find all root-to-leaf paths where
each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(root == NULL){
            return res;
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                vector<int> a(1, root->val);
                res.push_back(a);
                return res;
            }
        }
        res = pathSum(root->left, sum-root->val);
        vector<vector<int> > res2 = pathSum(root->right, sum-root->val);
        for(int i = 0; i < res.size(); i++){
            res[i].insert(res[i].begin(), root->val);
        }
        for(int i = 0; i < res2.size(); i++){
            res2[i].insert(res2[i].begin(), root->val);
            res.push_back(res2[i]);
        }
        return res;
    }
};
