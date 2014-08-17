/*****************************************

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

******************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> num;
        vector<vector<int> > res;

        if(k > n || k == 0){
            return res;
        }
        for(int i = 1; i <= n; i++){
            num.push_back(i);
        }
        res = combine(k, 0, num);
        for(auto it = res.begin(); it != res.end(); it++){
            reverse(it->begin(), it->end());
        }
        return res;
    }

    vector<vector<int> > combine(int k, int index, const vector<int>& num){
        vector<vector<int> > res;
        for(int i = index; i < num.size(); i++){
            if(k == 1){
                vector<int> one;
                one.push_back(num[i]);
                res.push_back(one);
            }
            else{
                vector<vector<int> > nextRes = combine(k-1, i+1, num);
                for(auto it = nextRes.begin(); it != nextRes.end(); it++){
                    it->push_back(num[i]);
                    res.push_back(*it);
                }
            }
        }

        return res;
    }
};
