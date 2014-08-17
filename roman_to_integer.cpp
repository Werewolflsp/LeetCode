/**********************************

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

**********************************/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int res;
    int romanToInt(string s) {
        res = 0;
        stack<char> buffer;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
            case 'I':
                pop(buffer);
                buffer.push(s[i]);
                break;
            case 'V':
                if(!buffer.empty() && buffer.top() == 'I'){
                    res += 4;
                    buffer.pop();
                }
                else{
                    res += 5;
                }
                pop(buffer);
                break;
            case 'X':
                if(!buffer.empty() && buffer.top() == 'I'){
                    res += 9;
                    buffer.pop();
                }
                else{
                    buffer.push(s[i]);
                }
                break;
            case 'L':
                if(!buffer.empty() && buffer.top() == 'X'){
                    res += 40;
                    buffer.pop();
                }
                else{
                    res += 50;
                }
                pop(buffer);
                break;
            case 'C':
                if(!buffer.empty() && buffer.top() == 'X'){
                    res += 90;
                    buffer.pop();
                }
                else{
                    buffer.push(s[i]);
                }
                break;
            case 'D':
                if(!buffer.empty() && buffer.top() == 'C'){
                    res += 400;
                    buffer.pop();
                }
                else{
                    res += 500;
                }
                pop(buffer);
                break;
            case 'M':
                if(!buffer.empty() && buffer.top() == 'C'){
                    res += 900;
                    buffer.pop();
                }
                else{
                    res += 1000;
                }
                pop(buffer);
                break;
            default:
                return 0;
            }
        }
        pop(buffer);
        return res;
    }

    int convertChar(char a){
        switch(a){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

    void pop(stack<char> &s){
        while(!s.empty()){
            char a = s.top();
            s.pop();
            switch(a){
                case 'I':
                    res += 1;
                    break;
                case 'V':
                    if(!s.empty() && s.top() == 'I'){
                        s.pop();
                        res += 4;
                    }
                    else{
                        res += 5;
                    }
                    break;
                case 'X':
                    if(!s.empty() && s.top() == 'I'){
                        s.pop();
                        res += 9;
                    }
                    else{
                        res += 10;
                    }
                    break;
                case 'L':
                    if(!s.empty() && s.top() == 'X'){
                        s.pop();
                        res += 40;
                    }
                    else{
                        res += 50;
                    }
                    break;
                case 'C':
                    if(!s.empty() && s.top() == 'X'){
                        s.pop();
                        res += 90;
                    }
                    else{
                        res += 100;
                    }
                    break;
                case 'D':
                    if(!s.empty() && s.top() == 'C'){
                        s.pop();
                        res += 400;
                    }
                    else{
                        res += 500;
                    }
                    break;
                case 'M':
                    if(!s.empty() && s.top() == 'C'){
                        s.pop();
                        res += 900;
                    }
                    else{
                        res += 1000;
                    }
                    break;
                default:
                    break;
            }
        }
    }
};
