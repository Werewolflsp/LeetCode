/************************************

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

************************************/

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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL){
            return true;
        }
        if(left != NULL && right == NULL ||
            left == NULL && right != NULL ||
            left->val != right->val){
            return false;
        }

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isSymmetric_iterative(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        vector<TreeNode *> v[2];
        int c = 0;
        int p = 1;
        v[p].push_back(root);

        while(v[p].size() != 0){
            vector<int> a;
            for(auto it = v[p].begin(); it != v[p].end(); it++){
                if((*it) == NULL){
                    a.push_back(-1);
                    continue;
                }
                a.push_back((*it)->val);
                if((*it)->left != NULL){
                    v[c].push_back((*it)->left);
                }
                else{
                    v[c].push_back(NULL);
                }
                if((*it)->right != NULL){
                    v[c].push_back((*it)->right);
                }
                else{
                    v[c].push_back(NULL);
                }
            }
            for(int i = 0, j = a.size() - 1; i < j; i++, j--){
                if(i == j || a[i] != a[j]){
                    return false;
                }
            }
            v[p].clear();
            p = !p;
            c = !c;
        }
        return true;
    }
};
