/******************************************

Given a m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

******************************************/

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m == 0){
            return;
        }
        int n = matrix[0].size();
        if(n == 0){
            return;
        }

        bool firstCol = false;
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                firstCol = true;
            }
        }

        bool firstRow = false;
        for(int i = 1; i < n; i++){
            if(matrix[0][i] == 0){
                firstRow = true;
            }
        }

        if(matrix[0][0] == 0){
            firstCol = true;
            firstRow = true;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
            if(matrix[0][i] == 0){
                for(int j = 1; j < m; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        if(firstCol){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }

        if(firstRow){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
    }
};
