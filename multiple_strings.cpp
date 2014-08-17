/***********************************

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

***********************************/

#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        string res(1, '0');
        int step = 0;
        for(int i = 0; i < n; i++){
            string temp = multiply(num2, num1[n-i-1]);
            res = add(temp + string(i, '0'), res);
        }
        int index = 0;
        while(res[index] == '0' && index != res.size() - 1){
            index++;
        }
        res = res.substr(index, string::npos);
        return res;
    }

    // the size of num1 is no less than that of num2
    string add(string num1, string num2){
        int n = num1.size();
        int m = num2.size();
        string res(n, '0');
        assert(n >= m);
        int temp;
        int step = 0;
        int i;
        for(i = 0; i < m; i++){
            temp = (num1[n-1-i] - '0') + (num2[m-1-i] - '0') + step;
            res[n-1-i] = (char)('0' + temp % 10);
            step = temp / 10;
        }
        for(; i < n; i++){
            temp = (num1[n-1-i] - '0') + step;
            res[n-1-i] = (char)('0' + temp % 10);
            step = temp / 10;
        }
        if(step != 0){
            res = "0" + res;
            res[0] += step;
        }
        return res;
    }

    string multiply(string num1, char num2){
        int n = num1.size();
        int mul = num2 - '0';
        string res(n, '0');
        int temp;
        int step = 0;
        for(int i = 0; i < num1.size(); i++){
            temp = (num1[n-1-i]-'0') * mul + step;
            res[n-1-i] = (char)('0' + temp % 10);
            step = temp / 10;
        }
        if(step != 0){
            res = "0" + res;
            res[0] += step;
        }
        return res;
    }
};
