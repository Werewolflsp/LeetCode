/****************************

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*****************************/

#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res[2];
        res[0] = "1";
        bool next = 1;
        for(int i = 1; i < n; i++){
            res[next].clear();
            for(int j = 0; j < res[!next].size();){
                int count = 0;
                do{
                    j++;
                    count++;
                }
                while(j < res[!next].size() && res[!next][j] == res[!next][j-1]);
                string temp(1, '0'+count);
                res[next] += temp + res[!next][j-1];
            }
            next = !next;
        }
        return res[!next];
    }
};
