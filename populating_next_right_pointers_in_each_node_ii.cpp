/************************************************************************

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*********************************************************************/

#include <cstring>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return;
        }
        vector<TreeLinkNode *> v[2];
        int c = 0;
        int p = 1;
        v[p].push_back(root);

        while(v[p].size() != 0){
            for(auto it = v[p].begin(); it != v[p].end(); it++){
                if(it+1 != v[p].end()){
                    (*it)->next = *(it+1);
                }
                else{
                    (*it)->next = NULL;
                }
                if((*it)->left != NULL){
                    v[c].push_back((*it)->left);
                }
                if((*it)->right != NULL){
                    v[c].push_back((*it)->right);
                }
            }

            v[p].clear();
            p = !p;
            c = !c;
        }
    }
};
