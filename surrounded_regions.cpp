/********************************

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*********************************/

#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.size() < 3){
            return;
        }

        for(int i = 0; i < board[0].size(); i++){
            flip(board, 0, i);
        }
        for(int i = 0; i < board[board.size() - 1].size(); i++){
            flip(board, board.size() - 1, i);
        }
        for(int i = 1; i < board.size() - 1; i++){
            if(board[i].size() > 0){
                flip(board, i, 0);
                flip(board, i, board[i].size() - 1);
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else {
                    if(board[i][j] == 'A'){
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }

    void flip(vector<vector<char> > &board, int i, int j){
        if(board[i][j] == 'O'){
            board[i][j] = 'A';
        }
        else{
            return;
        }
        if(i - 1 > 0){
            flip(board, i-1, j);
        }
        if(i + 1 < board.size()){
            flip(board, i+1, j);
        }
        if(j - 1 > 0){
            flip(board, i, j-1);
        }
        if(j + 1 < board[i].size()){
            flip(board, i, j+1);
        }
    }
};
