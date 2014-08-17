/**********************************

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

**********************************/

#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char> > &board, int a, int b){
        int i = a, j = b;
        while(i < 9 && j < 9){
            if(board[i][j] == '.'){
                for(int k = 0; k < 9; k++){
                    board[i][j] = '1' + k;
                    if(isValidSudoku(board, i, j) && solve(board, i, j)){
                        return true;
                    }
                }
                board[i][j] = '.';
                return false;
            }
            j++;
            if(j == 9){
                i++;
                j = 0;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board, int i, int j) {
        if(board[i][j] != '.'){
            for(int k = 0; k < 9; k++){
                if((k != i && board[k][j] == board[i][j]) ||
                    (k != j && board[i][k] == board[i][j])){
                    return false;
                }
            }
            for(int m = i / 3 * 3; m < i / 3 * 3 + 3; m++){
                for(int n = j / 3 * 3; n < j / 3 * 3 + 3; n++){
                    if(m != i && n != j && board[m][n] == board[i][j]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
