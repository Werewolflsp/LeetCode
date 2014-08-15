/*********************************

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*********************************/

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL){
            return res;
        }
        vector<TreeNode *> v[2];
        int c = 0;
        int p = 1;
        v[p].push_back(root);

        while(v[p].size() != 0){
            vector<int> a;
            for(auto it = v[p].begin(); it != v[p].end(); it++){
                a.push_back((*it)->val);
                if((*it)->left != NULL){
                    v[c].push_back((*it)->left);
                }
                if((*it)->right != NULL){
                    v[c].push_back((*it)->right);
                }
            }
            res.push_back(a);
            v[p].clear();
            p = !p;
            c = !c;
        }
        return res;
    }
};
