/*********************************

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

**********************************/

#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0' && (i == 0 || s[i-1] == '0')){
                return 0;
            }
        }
        if(s.size() == 0){
            return 0;
        }
        int *a = new int[s.size()];
        a[0] = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] != '0'){
                string s1 = s.substr(i-1, 2);
                if(atoi(s1.c_str()) <= 26){
                    if(i >= 2){
                        a[i] = a[i-1] * (s[i] != '0') + a[i-2];
                    }
                    else{
                        a[i] = a[i-1] * (s[i] != '0') + 1;
                    }
                }
                else{
                    a[i] = a[i-1] * (s[i] != '0');
                }
            }
            else{
                a[i] = a[i-1];
            }
        }
        int res = a[s.size()-1];
        delete[] a;
        return res;
    }
};
