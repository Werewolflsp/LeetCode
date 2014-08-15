/***********************************************

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

***********************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        for(int i = 0; i < numRows; i++){
            vector<int> n;
            n.push_back(1);
            for(int j = 1; j < i; j++){
                n.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            if(i > 0){
                n.push_back(1);
            }
            res.push_back(n);
        }
        return res;
    }
};
