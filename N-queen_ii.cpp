/**********************************

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

**********************************/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if(n <= 0){
            return 0;
        }
        vector<string> map;
        for(int i = 0; i < n; i++){
            map.push_back(string(n, '.'));
        }

        return solveNQueens(map, 0);
    }

    int solveNQueens(vector<string>& map, int i){
        int res = 0;
        for(int j = 0; j < map.size(); j++){
            if(map[i][j] == '.'){
                vector<string> newMap = map;
                newMap[i][j] = 'Q';
                if(i == newMap.size()-1){
                    res += 1;
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
                    res += solveNQueens(newMap, i+1);
                }
            }
        }

        return res;
    }
};
