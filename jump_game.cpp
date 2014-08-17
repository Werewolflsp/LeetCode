/**********************************

Given an array of non-negative integers, you are initially positioned at the first
index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

**********************************/

#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n <= 0){
            return false;
        }
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            if(maxLength >= i && i + A[i] >= n-1){
                return true;
            }
            if(A[i] == 0 && maxLength <= i){
                return false;
            }
            maxLength = max(maxLength, i+A[i]);
        }
        return false; // Just to make the compiler happy
    }
};
