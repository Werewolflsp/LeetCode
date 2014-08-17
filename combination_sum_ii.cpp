/**************************************

Given a collection of candidate numbers (C) and a target number (T), find all
unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order.
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

*************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > res = combinationSum(num, 0, target);
        for(auto it = res.begin(); it != res.end(); it++){
            reverse(it->begin(), it->end());
        }
        return res;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int start, int target){
        vector<vector<int> > res;
        for(int i = start; i < candidates.size(); i++){
            if(i == start || candidates[i] != candidates[i-1]){
                if(candidates[i] < target && i < candidates.size()-1){
                    vector<vector<int> > resPart = combinationSum(candidates, i+1,
                                                                  target-candidates[i]);
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
        }
        return res;
    }
};
