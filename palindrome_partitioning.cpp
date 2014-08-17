/**********************************

Given a string s, partition s such that every substring
of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

***********************************/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
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

        vector<vector<string> > *res = new vector<vector<string> >[n];

        for(int i = 0; i < n; i++){
            if(is[0][i]){
                vector<string> a;
                a.push_back(s.substr(0, i+1));
                res[i].push_back(a);
            }
            for(int j = 0; j < i; j++){
                if(is[j+1][i]){
                    for(auto it = res[j].begin(); it != res[j].end(); it++){
                        vector<string> a = *it;
                        a.push_back(s.substr(j+1, i-j));
                        res[i].push_back(a);
                    }
                }
            }
        }
        return res[n-1];
    }
};
