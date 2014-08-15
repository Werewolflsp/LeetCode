/*******************************************

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
containing all ones and return its area.

********************************************/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        if(n == 0){
            return 0;
        }

        int maxArea = 0;
        vector<vector<int> > height;
        for(int i = 0; i < m; i++){
            vector<int> h;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0'){
                    h.push_back(0);
                }
                else{
                    if(i == 0){
                        h.push_back(1);
                    }
                    else{
                        h.push_back(1+height[i-1][j]);
                    }
                }
            }
            height.push_back(h);
            maxArea = max(maxArea, largestRectangleArea(h));
        }
        return maxArea;
    }

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
