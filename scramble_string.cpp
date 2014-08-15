/******************************************

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

*********************************************/

#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()){
            return false;
        }

        bool ***a;
        int n = s1.size();
        a = new bool**[n];
        for(int i = 0; i < n; i++){
            a[i] = new bool*[n];
            for(int j = 0; j < n; j++){
                a[i][j] = new bool[n];
                memset(a[i][j], false, n * sizeof(bool));
            }
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(i + k < n){
                    for(int j = 0; j < n; j++){
                        if(j + k < n){
                            if(k == 0){
                                a[i][j][k] = s1[i] == s2[j];
                            }
                            else{
                                for(int m = 0; m < k; m++){
                                    a[i][j][k] = (a[i][j+m+1][k-m-1] && a[i+k-m][j][m]) ||
                                                    (a[i][j][m] && a[i+m+1][j+m+1][k-m-1]) ||
                                                    (s1.substr(i, k+1) == s2.substr(j, k+1));
                                    if(a[i][j][k]){
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return a[0][0][n-1];
    }
};
