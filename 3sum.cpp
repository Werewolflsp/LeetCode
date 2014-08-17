/**********************************

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*********************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        return threeSum(num, 0, 0, 0, 3);
    }

    vector<vector<int> > threeSum(vector<int> &num, int start, int sum,
                                  int sumNow, int count) {
        vector<vector<int> > res;
        if(count == 0){
        }
        else if(count == 1){
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
                if(sumNow + num[i] > sum && num[i] >= 0){
                    break;
                }
                else{
                    vector<vector<int> > resPart = threeSum(num, i+1, sum,
                                                            sumNow+num[i], count-1);
                    for(auto it = resPart.begin(); it != resPart.end(); it++){
                        it->insert(it->begin(), num[i]);
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
