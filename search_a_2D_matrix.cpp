/***************************************

Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

****************************************/

#include <vector>
using namespace std;

class Solution {
public:
    int m, n;

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        m = matrix.size();
        if(m == 0){
            return false;
        }
        n = matrix[0].size();
        if(n == 0){
            return false;
        }
        return searchMatrix(matrix, target, 0, m*n-1);
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target, int i, int j) {
        if(i > j){
            return false;
        }

        int index = (i + j ) / 2;
        if(matrix[index/n][index%n] == target){
            return true;
        }
        else if(matrix[index/n][index%n] < target){
            return searchMatrix(matrix, target, index+1, j);
        }
        else{
            return searchMatrix(matrix, target, i, index-1);
        }
    }
};
