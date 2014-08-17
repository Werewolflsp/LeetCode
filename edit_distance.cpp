/************************************

Given two words word1 and word2, find the minimum number of steps required
to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

************************************/

#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m == 0 && n == 0){
            return 0;
        }
        else if(m == 0){
            return n;
        }
        else if(n == 0){
            return m;
        }

        int **a = new int*[m];
        for(int i = 0; i < m; i++){
            a[i] = new int[n];
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    if(word1[i] == word2[j]){
                        a[i][j] = 0;
                    }
                    else{
                        a[i][j] = 1;
                    }
                }
                else if(i == 0){
                    if(word1[i] == word2[j]){
                        a[i][j] = j;
                    }
                    else{
                        a[i][j] = min(j, a[i][j-1]) + 1;
                    }
                }
                else if(j == 0){
                    if(word1[i] == word2[j]){
                        a[i][j] = i;
                    }
                    else{
                        a[i][j] = min(i, a[i-1][j]) + 1;
                    }
                }
                else{
                    if(word1[i] == word2[j]){
                        a[i][j] = a[i-1][j-1];
                    }
                    else{
                        a[i][j] = min(a[i-1][j-1] + 1, a[i][j-1] + 1);
                        a[i][j] = min(a[i][j], a[i-1][j] + 1);
                    }
                }
            }
        }

        int res = a[m-1][n-1];
        for(int i = 0; i < m; i++){
            delete[] a[i];
        }
        delete[] a;
        return res;
    }
};
