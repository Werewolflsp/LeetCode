/*************************************

Given a string s and a dictionary of words dict, determine if s
can be segmented into a space-separated sequence of one or more
dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

**************************************/

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        for(int i = 0; i < s.size(); i++){
            bool found = false;
            for(auto it = dict.begin(); it != dict.end(); it++){
                if(it->find(s.substr(i, 1)) != string::npos){
                    found = true;
                    break;
                }
            }
            if(found == false){
                return false;
            }
        }

        for(auto it = dict.begin(); it != dict.end(); it++){
            if(s.find(*it) == 0){
                if(it->size() == s.size()){
                    return true;
                }
                if(wordBreak(s.substr(it->size(), string::npos), dict)){
                    return true;
                };
            }
        }

        return false;
    }
};
