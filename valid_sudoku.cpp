/***********************************

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with
the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the
filled cells need to be validated.

************************************/

#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    for(int k = 0; k < 9; k++){
                        if((k != i && board[k][j] == board[i][j]) ||
                            (k != j && board[i][k] == board[i][j])){
                            return false;
                        }
                    }
                    for(int m = i / 3 * 3; m < i / 3 * 3 + 3; m++){
                        for(int n = j / 3 * 3; n < j / 3 * 3 + 3; n++){
                            if(!(m == i && n == j) && board[m][n] == board[i][j]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
