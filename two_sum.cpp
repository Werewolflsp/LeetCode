/**********************************

Given an array of integers, find two numbers such that they add up to a specific
target number.

The function twoSum should return indices of the two numbers such that they add
up to the target, where index1 must be less than index2. Please note that your
returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

**********************************/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int, vector<int> > buffers;
        for(int i = 0; i < numbers.size(); i++){
            buffers[numbers[i]].push_back(i+1);
        }
        for(auto it = buffers.begin(); it != buffers.end(); it++){
            auto et = buffers.find(target-it->first);
            if(et != buffers.end()){
                if(et != it){
                    res.push_back((it->second).front());
                    res.push_back((et->second).front());
                    break;
                }
                else if((it->second).size() > 1){
                    res.push_back((it->second).front());
                    res.push_back((et->second).back());
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
