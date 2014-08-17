/**********************************

Given an array S of n integers, are there elements a, b, c, and d in S such that
a + b + c + d = target? Find all unique quadruplets in the array which gives the
sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

***********************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > res = threeSum(num, 0, target, 0, 4);
        for(auto it = res.begin(); it != res.end(); it++){
            reverse(it->begin(), it->end());
        }
        return res;
    }

    vector<vector<int> > threeSum(vector<int> &num, int start, int sum,
                                  int sumNow, int count) {
        vector<vector<int> > res;
        if(count == 0){
        }
        else if(count == 1){
            if(sumNow + num.back() < sum){
                return res;
            }
            for(int i = start; i < (int)num.size(); i++){
                if(sumNow + num[i] == sum){
                    vector<int> a(1, num[i]);
                    res.push_back(a);
                }
                else if(sumNow + num[i] > sum && num[i] >= 0){
                    break;
                }
                while(i < num.size()-1 && num[i] == num[i+1]){
                    i++;
                }
            }
        }
        else{
            for(int i = start; i < (int)num.size()-count+1; i++){
                if(sumNow + count * num.back() < sum || sumNow + count * num[start]
                   > sum){
                    return res;
                }
                if(sumNow + num[i] > sum && num[i] >= 0){
                    break;
                }
                else{
                    vector<vector<int> > resPart = threeSum(num, i+1, sum, sumNow+num[i],
                                                            count-1);
                    for(auto it = resPart.begin(); it != resPart.end(); it++){
                        it->push_back(num[i]);
                        res.push_back(*it);
                    }
                }
                while(i < num.size()-1 && num[i] == num[i+1]){
                    i++;
                }
            }
        }
        return res;
    }
};
