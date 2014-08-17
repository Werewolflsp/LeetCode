/*************************

Given a set of candidate numbers (C) and a target number (T), find all unique
combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order.
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

**************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res = combinationSum(candidates, 0, target);
        for(auto it = res.begin(); it != res.end(); it++){
            reverse(it->begin(), it->end());
        }
        return res;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int start, int target){
        vector<vector<int> > res;
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] < target){
                vector<vector<int> > resPart = combinationSum(candidates, i, target-candidates[i]);
                for(auto it = resPart.begin(); it != resPart.end(); it++){
                    it->push_back(candidates[i]);
                    res.push_back(*it);
                }
            }
            else if(candidates[i] == target){
                vector<int> temp(1, target);
                res.push_back(temp);
            }
        }
        return res;
    }
};
