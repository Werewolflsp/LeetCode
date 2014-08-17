/**********************************

Given n non-negative integers a1, a2, ..., an, where each represents a point at
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms
a container, such that the container contains the most water.

Note: You may not slant the container.

**********************************/

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int *next = new int[height.size()];
        int left = 0;
        for(int i = 1; i < height.size(); i++){
            if(height[i] < height[i-1]){
                for(int j = left; j < i; j++){
                    next[j] = i-1;
                }
                left = i;
            }
        }
        for(int j = left; j < height.size(); j++){
            next[j] = height.size()-1;
        }

        int res = 0;
        left = 0;
        for(int i = 0; i < height.size(); i++){
            if(i > 0 && height[i] <= height[left]){
                continue;
            }
            else{
                left = i;
            }
            for(int j = next[i]; j < height.size(); j = next[j+1]){
                res = max(res, (j-i)*min(height[i], height[j]));
                if(j == height.size()-1){
                    break;
                }
            }
        }
        delete[] next;
        return res;
    }
};
