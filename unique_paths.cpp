/**********************************

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

*********************************/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0){
            return 0;
        }

        int **a = new int*[m];
        for(int i = 0; i < m; i++){
            a[i] = new int[n];
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    a[i][j] = 1;
                }
                else if(i == 0){
                    a[i][j] = a[i][j-1];
                }
                else if(j == 0){
                    a[i][j] = a[i-1][j];
                }
                else{
                    a[i][j] = a[i-1][j] + a[i][j-1];
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
