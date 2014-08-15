/**********************************

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

***********************************/

#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses(s, 0, 4);
    }

    vector<string> restoreIpAddresses(const string& s, int start, int n){
        vector<string> res;
        if(s.size() - start > 3*n || s.size() - start < n){
            return res;
        }

        if(n == 1){
            string ip = s.substr(start, string::npos);
            if(atoi(ip.c_str()) <= 255 && !(ip.size() > 1 && ip[0] == '0')){
                res.push_back(ip);
            }
            return res;
        }
        for(int i = 0; i < 3; i++){
            vector<string> temp = restoreIpAddresses(s, start + i + 1, n-1);
            string ip = s.substr(start, i+1);
            if(atoi(ip.c_str()) > 255 || (ip.size() > 1 && ip[0] == '0')){
                continue;
            }
            for(auto it = temp.begin(); it != temp.end(); it++){
                res.push_back(ip + "." + *it);
            }
        }

        return res;
    }
};
