/**************************************

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

***************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        return subset(S, 0);
    }

    vector<vector<int> > subset(const vector<int>& S, int index){
        vector<vector<int> > res;
        res.push_back(S);

        for(int i = index; i < S.size(); i++){
            vector<int> subS = S;
            subS.erase(subS.begin() + i);
            vector<vector<int> > subRes = subset(subS, i);
            res.insert(res.end(), subRes.begin(), subRes.end());
        }

        return res;
    }
};
