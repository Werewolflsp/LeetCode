/***********************************

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

************************************/

#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        if(s1.size() == 0){
            return s2 == s3;
        }
        if(s2.size() == 0){
            return s1 == s3;
        }

        bool **a = new bool*[s1.size() + 1];
        for(int i = 0; i <= s1.size(); i++){
            a[i] = new bool[s2.size() + 1];
            memset(a[i], false, (s2.size()+1)*sizeof(bool));

            for(int j = 0; j <= s2.size(); j++){
                if(i == 0 && j == 0){
                    a[i][j] = true;
                }
                else if(i == 0){
                    a[i][j] = a[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if(j == 0){
                    a[i][j] = a[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                else{
                    a[i][j] = (a[i][j-1] && s2[j-1] == s3[i+j-1]) || (a[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
            }
        }
        bool res = a[s1.size()][s2.size()];

        for(int i = 0; i <= s1.size(); i++){
            delete[] a[i];
        }
        delete[]a;

        return res;
    }
};
