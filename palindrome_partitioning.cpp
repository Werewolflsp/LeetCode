/**************************

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

**************************/

#include <cstring>
#include <string>
using namespace std;

class Solution {
public:

    int minCut(string s) {
        int n = s.size();
        bool **is = new bool*[n];
        for(int i = 0; i < n; i++){
            is[i] = new bool[n];
            memset(is[i], false, sizeof(is[i]));
            is[i][i] = true;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                is[i][j] = s[i] == s[j];
                is[j][i] = is[i][j];
            }
        }

        for(int m = 3; m <= n; m++){
            for(int i = 0; i < n-m+1; i++){
                int j = i + m - 1;
                is[i][j] = (s[i] == s[j] && is[i+1][j-1]);
                is[j][i] = is[i][j];
            }
        }

        int *p = new int[n];
        memset(p, 0, sizeof(p));
        for(int i = 1; i < n; i++){
            if(is[0][i]){
                p[i] = 0;
                continue;
            }
            int min = p[i-1] + 1;
            for(int j = 0; j < i; j++){
                if(is[j+1][i] && p[j]+1 < min){
                    min = p[j] + 1;
                }
            }
            p[i] = min;
        }
        return p[n-1];
    }
};
