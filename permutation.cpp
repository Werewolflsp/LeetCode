/***********************************

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

***********************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > res;

    vector<vector<int> > permute(vector<int> &num) {
        res.clear();
        permute(num, 0);
        return res;
    }

    void permute(vector<int> &num, int start){
        if(start == num.size()-1){
            res.push_back(num);
            return;
        }
        else if(start > num.size() - 1){
            return;
        }
        for(int i = start; i < num.size(); i++){
            int temp = num[start];
            num[start] = num[i];
            num[i] = temp;
            permute(num, start+1);
            num[i] = num[start];
            num[start] = temp;
        }
    }
};
