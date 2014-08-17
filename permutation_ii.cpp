/***************************************

Given a collection of numbers that might contain duplicates,
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

***************************************/

#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    set<vector<int> > res;

    vector<vector<int> > permuteUnique(vector<int> &num) {
        res.clear();
        permute(num, 0);
        vector<vector<int> > vec;
        for(auto it = res.begin(); it != res.end(); it++){
            vec.push_back(*it);
        }
        return vec;
    }

    void permute(vector<int> &num, int start){
        if(start == num.size()-1){
            res.insert(num);
            return;
        }
        else if(start > num.size() - 1){
            return;
        }
        for(int i = start; i < num.size(); i++){
            if(i == start || num[start] != num[i]){
                int temp = num[start];
                num[start] = num[i];
                num[i] = temp;
                permute(num, start+1);
                num[i] = num[start];
                num[start] = temp;
            }
        }
    }
};
