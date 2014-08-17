/*****************************************

Given a string containing just the characters '(' and ')', find the length of the
longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()",
which has length = 4.

******************************************/

#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> leftIndex;
        vector<int> start;
        vector<int> ending;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                leftIndex.push(i);
            }
            else{
                if(!leftIndex.empty()){
                    int left = leftIndex.top();
                    while(!ending.empty() && ending.back() >= left - 1){
                        if(ending.back() == left -1){
                            left = start.back();
                        }
                        start.erase(start.begin() + start.size() - 1);
                        ending.erase(ending.begin() + ending.size() - 1);
                    }
                    start.push_back(left);
                    ending.push_back(i);
                    leftIndex.pop();
                }
            }
        }
        int maxLength = 0;
        for(int i = 0; i < start.size(); i++){
            maxLength = max(maxLength, ending[i]-start[i]+1);
        }
        return maxLength;
    }
};
