/***************************************

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

***************************************/

#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> exprs;
        int a, b;
        for(auto iter = tokens.begin(); iter != tokens.end(); iter++){
            if(iter->compare("+") == 0){
                if(exprs.size() < 2){
                    return -1; //error
                }
                else{
                    b = exprs.back();
                    exprs.pop_back();
                    a = exprs.back();
                    exprs.pop_back();
                    exprs.push_back(a+b);
                }
            }
            else if(iter->compare("-") == 0){
                if(exprs.size() < 2){
                    return -1; //error
                }
                else{
                    b = exprs.back();
                    exprs.pop_back();
                    a = exprs.back();
                    exprs.pop_back();
                    exprs.push_back(a-b);
                }
            }
            else if(iter->compare("*") == 0){
                if(exprs.size() < 2){
                    return -1; //error
                }
                else{
                    b = exprs.back();
                    exprs.pop_back();
                    a = exprs.back();
                    exprs.pop_back();
                    exprs.push_back(a*b);
                }
            }
            else if(iter->compare("/") == 0){
                if(exprs.size() < 2){
                    return -1; //error
                }
                else{
                    b = exprs.back();
                    exprs.pop_back();
                    a = exprs.back();
                    exprs.pop_back();
                    exprs.push_back(a/b);
                }
            }
            else{
                exprs.push_back(atoi(iter->c_str()));
            }
        }
        return exprs.back();
    }
};
