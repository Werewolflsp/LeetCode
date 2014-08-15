/********************************

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    vector<TreeNode *> generateTrees(int n) {
        vector<int> num;
        for(int i = 1; i <= n; i++){
            num.push_back(i);
        }
        return generateTrees(num);
    }

    vector<TreeNode *> generateTrees(const vector<int>& a){
        vector<TreeNode *> res;
        if(a.size() == 0){
            res.push_back(NULL);
        }
        else{
            for(int i = 0; i < a.size(); i++){
                vector<int> b, c;
                for(int j = 0; j < i; j++){
                    b.push_back(a[j]);
                }
                for(int j = i+1; j < a.size(); j++){
                    c.push_back(a[j]);
                }
                vector<TreeNode *> bt = generateTrees(b);
                vector<TreeNode *> ct = generateTrees(c);
                for(auto it = bt.begin(); it != bt.end(); it++){
                    for(auto et = ct.begin(); et != ct.end(); et++){
                        TreeNode *root = new TreeNode(a[i]);
                        root->left = *it;
                        root->right = *et;
                        res.push_back(root);
                    }
                }
            }
        }

        return res;
    }
};
