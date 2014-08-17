/*****************************

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*****************************/

#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();

        string small;
        string large;
        int minLength;
        int maxLength;

        if(m <= n){
            minLength = m;
            maxLength = n;
            small = a;
            large = b;
        }
        else{
            minLength = n;
            maxLength = m;
            small = b;
            large = a;
        }

        string res(maxLength, '0');

        char step = '0';
        for(int i = 0; i < minLength; i++){
            int count = 0;
            if(a[m-1-i] == '1'){
                count++;
            }
            if(b[n-1-i] == '1'){
                count++;
            }
            if(step == '1'){
                count++;
            }

            if(count == 3){
                res[maxLength-1-i] = '1';
                step = '1';
            }
            else if(count == 2){
                res[maxLength-1-i] = '0';
                step = '1';
            }
            else if(count == 1){
                res[maxLength-1-i] = '1';
                step = '0';
            }
            else{
                res[maxLength-1-i] = '0';
                step = '0';
            }
        }

        for(int i = minLength; i < maxLength; i++){
            int count = 0;
            if(large[maxLength-i-1] == '1'){
                count++;
            }
            if(step == '1'){
                count++;
            }

            if(count == 2){
                res[maxLength-1-i] = '0';
                step = '1';
            }
            else if(count == 1){
                res[maxLength-1-i] = '1';
                step = '0';
            }
            else{
                res[maxLength-1-i] = '0';
                step = '0';
            }
        }

        if(step == '1'){
            res.insert(0, 1, '1');
        }

        return res;
    }
};
