/******************************************

Given a matrix of m x n elements (m rows, n columns), return all elements of
the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

******************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0){
            return res;
        }
        int n = matrix[0].size();
        if(n == 0){
            return res;
        }

        bool **visited = new bool*[m];
        for(int i = 0; i < m; i++){
            visited[i] = new bool[n];
            memset(visited[i], false, n*sizeof(bool));
        }

        int i = 0, j = 0;
        int a = 0; // direction, 0 right, 1 down, 2, left, 3 up
        while(true){
            res.push_back(matrix[i][j]);
            visited[i][j] = true;

            bool ok = false;
            bool turned = false;
            while(!ok){
                if(a == 0 && j < n-1 && !visited[i][j+1]){
                    j++;
                    ok = true;
                }
                else if(a == 1 && i < m-1 && !visited[i+1][j]){
                    i++;
                    ok = true;
                }
                else if(a == 2 && j > 0 && !visited[i][j-1]){
                    j--;
                    ok = true;
                }
                else if(a == 3 && i > 0 && !visited[i-1][j]){
                    i--;
                    ok = true;
                }
                else{
                    if(turned){
                        for(int k = 0; k < m; k++){
                            delete[] visited[k];
                        }
                        delete[] visited;
                        return res;
                    }
                    turned = true;
                    a = (a+1) % 4;
                }
            }
        }
    }
};
