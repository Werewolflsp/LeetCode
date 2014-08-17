/*****************************************

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*****************************************/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool **visited;

    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if(m == 0){
            return word.size() == 0;
        }
        int n = board[0].size();
        if(n == 0){
            return word.size() == 0;
        }

        if(word.size() == 0){
            return false;
        }

        visited = new bool*[m];
        for(int i = 0; i < m; i++){
            visited[i] = new bool[n];
            memset(visited[i], false, n*sizeof(bool));
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(exist(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool exist(const vector<vector<char> >& board, const string& word, int i, int j, int index){
        if(index >= word.size()-1){
            return true;
        }
        index++;

        visited[i][j] = true;

        if(i > 0 && !visited[i-1][j] && board[i-1][j] == word[index]){
            if(exist(board, word, i-1, j, index)){
                return true;
            }
        }
        if(i < board.size()-1 && !visited[i+1][j] && board[i+1][j] == word[index]){
            if(exist(board, word, i+1, j, index)){
                return true;
            }
        }
        if(j > 0 && !visited[i][j-1] && board[i][j-1] == word[index]){
            if(exist(board, word, i, j-1, index)){
                return true;
            }
        }
        if(j < board[i].size()-1 && !visited[i][j+1] && board[i][j+1] == word[index]){
            if(exist(board, word, i, j+1, index)){
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }
};
