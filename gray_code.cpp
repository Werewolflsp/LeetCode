/***************************************

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the
sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about
that.

****************************************/

#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        vector<string> grayString = grayCodeString(n);
        for(auto it = grayString.begin(); it != grayString.end(); it++){
            res.push_back((int) strtol((*it).c_str(), NULL, 2));
        }
        return res;
    }

    vector<string> grayCodeString(int n){
        vector<string> res;
        if(n == 0){
            res.push_back("0");
        }
        if(n == 1){
            res.push_back("0");
            res.push_back("1");
        }
        else if(n > 0){
            vector<string> subRes = grayCodeString(n-1);
            for(auto it = subRes.begin(); it != subRes.end(); it++){
                res.push_back(string("0") + *it);
            }
            for(auto it = subRes.rbegin(); it != subRes.rend(); it++){
                res.push_back(string("1") + *it);
            }
        }
        return res;
    }
};
