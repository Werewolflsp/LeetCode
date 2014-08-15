/***************************************

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

***************************************/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        height.push_back(0);
        stack<int> s;
        int i = 0;
        while(i < height.size()){
            if(s.empty() || height[s.top()] <= height[i]){
                s.push(i++);
            }
            else {
                int t = s.top();
                s.pop();
                maxArea = max(maxArea, height[t] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        height.erase(height.begin() + i -1);
        return maxArea;
    }
};
