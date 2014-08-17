/********************************

Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*********************************/

#include <stack>
using namespace std;

// There are better solutions...the worst case is O(n2) here...

class Solution {
public:
    int trap(int A[], int n) {
        int *B = new int[n];
        for(int i = 0; i < n; i++){
            B[i] = 0;
        }
        int rightTop = -1;
        stack<int> leftTop;
        for(int i = 1; i < n; i++){
            if(A[i] <= A[i-1]){
                if(rightTop > 0){
                    if(leftTop.size() > 0){
                        while(A[leftTop.top()] < A[rightTop] && leftTop.size() > 1){
                            leftTop.pop();
                        }
                        int top = min(A[leftTop.top()], A[rightTop]);
                        for(int j = leftTop.top() + 1; j < rightTop; j++){
                            B[j] = top;
                        }
                    }
                    rightTop = -1;
                }
                while(leftTop.size() > 0 && A[leftTop.top()] <= A[i-1]){
                    leftTop.pop();
                }
                leftTop.push(i-1);
            }
            else{
                rightTop = i;
                if(i == n-1){
                    if(leftTop.size() > 0){
                        while(A[leftTop.top()] < A[rightTop] && leftTop.size() > 1){
                            leftTop.pop();
                        }
                        int top = min(A[leftTop.top()], A[rightTop]);
                        for(int j = leftTop.top() + 1; j < rightTop; j++){
                            B[j] = top;
                        }
                    }
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            int part = B[i] - A[i];
            if(part > 0){
                res += part;
            }
        }
        delete[] B;
        return res;
    }
};
