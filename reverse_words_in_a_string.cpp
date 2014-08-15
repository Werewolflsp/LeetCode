/******************************************************

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

******************************************************/

#include<string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string res;
        for(size_t i = s.find_first_not_of(" "), j = 0; j != string::npos && i != string::npos;){
            j = s.find(" ", i + 1);
            res = s.substr(i, j - i) + res;
            i = s.find_first_not_of(" ", j);
            if(i != string::npos){
                res = string(" ") + res;
            }
            else{
                break;
            }
        }
        s = res;
    }
};
