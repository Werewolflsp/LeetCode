/*******************************************

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*******************************************/

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0){
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n == 0){
            return 0;
        }

        int **a = new int*[m];
        for(int i = 0; i < m; i++){
            a[i] = new int[n];
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    a[i][j] = 0;
                }
                else{
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
        }

        int res = a[m-1][n-1];
        for(int i = 0; i < m; i++){
            delete[] a[i];
        }
        delete[] a;

        return res;
    }
};
