/**********************************

Write a function to find the longest common prefix string amongst an array of strings.

**********************************/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if(strs.empty()){
            return res;
        }
        for(int i = 0; i < strs[0].size(); i++){
            char a = strs[0][i];
            bool notIs = false;
            for(auto it = strs.begin() + 1; it != strs.end(); it++){
                if((*it)[i] != a){
                    notIs = true;
                    break;
                }
            }
            if(notIs){
                break;
            }
            else{
                res += string(1, a);
            }
        }
        return res;
    }
};
