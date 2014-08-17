/********************************

Given an integer n, generate a square matrix filled with elements
from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

********************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> one(n, 0);
        vector<vector<int> > res(n, one);
        if(n == 0){
            return res;
        }

        int i = 0, j = 0;
        int num = 1;
        int a = 0; // direction, 0 right, 1 down, 2, left, 3 up
        while(true){
            res[i][j] = num;
            num++;

            bool ok = false;
            bool turned = false;
            while(!ok){
                if(a == 0 && j < n-1 && res[i][j+1] == 0){
                    j++;
                    ok = true;
                }
                else if(a == 1 && i < n-1 && res[i+1][j] == 0){
                    i++;
                    ok = true;
                }
                else if(a == 2 && j > 0 && res[i][j-1] == 0){
                    j--;
                    ok = true;
                }
                else if(a == 3 && i > 0 && res[i-1][j] == 0){
                    i--;
                    ok = true;
                }
                else{
                    if(turned){
                        return res;
                    }
                    turned = true;
                    a = (a+1) % 4;
                }
            }
        }
    }
};
