/**********************************

Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid
but "(]" and "([)]" are not.

**********************************/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
            case '(':
            case '[':
            case '{':
                tmp.push(s[i]);
                break;
            case ')':
                if(tmp.empty() || tmp.top() != '('){
                    return false;
                }
                else{
                    tmp.pop();
                }
                break;
            case ']':
                if(tmp.empty() || tmp.top() != '['){
                    return false;
                }
                else{
                    tmp.pop();
                }
                break;
            case '}':
                if(tmp.empty() || tmp.top() != '{'){
                    return false;
                }
                else{
                    tmp.pop();
                }
                break;
            default:
                return false;
            }
        }
        return tmp.empty();
    }
};
