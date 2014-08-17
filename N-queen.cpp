/***********************************************************

The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

***********************************************************/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if(n <= 0){
            return res;
        }
        vector<string> map;
        for(int i = 0; i < n; i++){
            map.push_back(string(n, '.'));
        }

        return solveNQueens(map, 0);
    }

    vector<vector<string> > solveNQueens(vector<string>& map, int i){
        vector<vector<string> > res;
        for(int j = 0; j < map.size(); j++){
            if(map[i][j] == '.'){
                vector<string> newMap = map;
                newMap[i][j] = 'Q';
                if(i == newMap.size()-1){
                    for(int m = 0; m < newMap.size(); m++){
                        for(int n = 0; n < newMap.size(); n++){
                            if(newMap[m][n] == 'K'){
                                newMap[m][n] = '.';
                            }
                        }
                    }
                    res.push_back(newMap);
                }
                else{
                    for(int k = 1; i+k < newMap.size(); k++){
                        newMap[i+k][j] = 'K';
                        if(j - k >= 0){
                            newMap[i+k][j-k] = 'K';
                        }
                        if(j + k < map.size()){
                            newMap[i+k][j+k] = 'K';
                        }
                    }
                    vector<vector<string> > part = solveNQueens(newMap, i+1);
                    res.insert(res.end(), part.begin(), part.end());
                }
            }
        }

        return res;
    }
};
