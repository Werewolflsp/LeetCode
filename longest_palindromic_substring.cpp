/**********************************

Given a string S, find the longest palindromic substring in S. You may assume
that the maximum length of S is 1000, and there exists one unique longest
palindromic substring.

**********************************/

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool **a = new bool*[s.size()];
        int start = 0, length = 1;
        for(int i = 0; i < s.size(); i++){
            a[i] = new bool[s.size()-i];
            memset(a[i], false, (s.size()-i)*sizeof(false));
            if(i == 0){
                memset(a[i], true, (s.size()-i)*sizeof(false));
            }
            else if(i == 1){
                for(int j = 0; j < s.size() - i; j++){
                    a[i][j] = s[j] == s[j+i];
                    if(a[i][j]){
                        start = j;
                        length = i+1;
                    }
                }
            }
            else if(i > 1){
                for(int j = 0; j < s.size() - i; j++){
                    a[i][j] = s[j] == s[j+i] && a[i-2][j+1];
                    if(a[i][j]){
                        start = j;
                        length = i+1;
                    }
                }
            }
        }
        for(int i = 0; i < s.size(); i++){
            delete[] a[i];
        }
        delete[] a;
        return s.substr(start, length);
    }
};
