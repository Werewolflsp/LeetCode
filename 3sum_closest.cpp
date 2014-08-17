/**********************************

Given an array S of n integers, find three integers in S such that the sum
is closest to a given number, target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

**********************************/

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int res;
    bool init;

    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        init = true;
        threeSum(num, 0, target, 0, 3);
        return res;
    }

    void threeSum(vector<int> &num, int start, int sum, int sumNow, int count) {
        if(count == 0){
        }
        else if(count == 1){
            if(sumNow < sum && sumNow + num.back() < sum){
                int temp = sumNow + num.back();
                if(init){
                    res = temp;
                    init = false;
                }
                else{
                    res = (abs(temp-sum) < abs(res-sum))?temp:res;
                }
                return;
            }
            for(int i = start; i < (int)num.size(); i++){
                int temp = sumNow + num[i];
                if(init){
                    res = temp;
                    init = false;
                }
                else{
                    res = (abs(temp-sum) < abs(res-sum))?temp:res;
                }
                if(!init && sumNow + num[i] > sum && sumNow + num[i] - sum > abs(res - sum)
                   && num[i] >= 0){
                    break;
                }
                while(i < num.size()-1 && num[i] == num[i+1]){
                    i++;
                }
            }
        }
        else{
            for(int i = start; i < (int)num.size()-count+1; i++){
                if(!init && sumNow + num[i] > sum && sumNow + num[i] - sum > abs(res - sum)
                   && num[i] >= 0){
                    break;
                }
                else{
                    threeSum(num, i+1, sum, sumNow+num[i], count-1);
                }
                while(i < num.size()-1 && num[i] == num[i+1]){
                    i++;
                }
            }
        }
    }
};
