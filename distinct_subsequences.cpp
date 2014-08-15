/*************************************

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by
deleting some (can be none) of the characters without disturbing the relative positions
of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*************************************/

#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.size() < T.size()){
            return 0;
        }
        if(T.size() == 0){
            return S.size();
        }

        // a[i][j] indicates the result of numDistinct(S.substr(0, i+1), T.substr(0, j+1))
        int **a = new int*[S.size()];
        for(int i = 0; i < S.size(); i++){
            a[i] = new int[T.size()];
            memset(a[i], 0, T.size()*sizeof(int));
            if(i == 0){
                a[i][0] = S[i] == T[0];
            }
            else{
                a[i][0] = a[i-1][0] + (S[i] == T[0]);
            }
        }

        for(int i = 1; i < S.size(); i++){
            int temp = min(i, (int)T.size()-1);
            for(int j = 1; j <= temp; j++){
                if(S[i] == T[j]){
                    a[i][j] = a[i-1][j-1] + a[i-1][j];
                }
                else{
                    a[i][j] = a[i-1][j];
                }
            }
        }

        return a[S.size()-1][T.size()-1];
    }
};
