/**********************************

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

***********************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        return subsetWithDup(S, 0);
    }

    vector<vector<int> > subsetWithDup(const vector<int>& S, int index){
        vector<vector<int> > res;
        res.push_back(S);

        int a = 0;
        for(int i = index; i < S.size(); i++){
            if(i == index || a != S[i]){
                a = S[i];
                vector<int> subS = S;
                subS.erase(subS.begin() + i);
                vector<vector<int> > subRes = subsetWithDup(subS, i);
                res.insert(res.end(), subRes.begin(), subRes.end());
            }
        }

        return res;
    }
};
