/**********************************

Given a sorted array of integers, find the starting and ending position of
a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

**********************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        return searchRange(A, 0, n-1, target);
    }

    vector<int> searchRange(int A[], int start, int end, int target){
        if(start > end){
            return vector<int>(2, -1);
        }
        int index = (start + end) / 2;
        if(A[index] < target){
            return searchRange(A, index + 1, end, target);
        }
        else if(A[index] > target){
            return searchRange(A, start, index - 1, target);
        }
        else{
            int i;
            vector<int> res;
            for(i = index - 1; i >= start; i--){
                if(A[i] != target){
                    res.push_back(i+1);
                    break;
                }
            }
            if(res.empty()){
                res.push_back(start);
            }
            for(i = index + 1; i <= end; i++){
                if(A[i] != target){
                    res.push_back(i-1);
                    break;
                }
            }
            if(res.size() == 1){
                res.push_back(end);
            }
            return res;
        }
    }
};
