/*********************************

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

**********************************/

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
        if(n == 0){
            return 0;
        }

        int **a = new int*[m];
        for(int i = 0; i < m; i++){
            a[i] = new int[n];
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    a[i][j] = grid[i][j];
                }
                else if(i == 0){
                    a[i][j] = grid[i][j] + a[i][j-1];
                }
                else if(j == 0){
                    a[i][j] = grid[i][j] + a[i-1][j];
                }
                else{
                    a[i][j] = grid[i][j] + min(a[i][j-1], a[i-1][j]);
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
