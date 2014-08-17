/**************************************

Given an array of non-negative integers, you are initially positioned at the first
index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index
0 to 1, then 3 steps to the last index.)

**************************************/

#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int maxLength = 0;
        int step = 0;
        int lastMax = 0;
        for(int i = 0; i < n; i++){
            if(i > lastMax){
                step++;
                lastMax = maxLength;
            }
            maxLength = max(maxLength, i+A[i]);
        }
        return step;
    }
};
