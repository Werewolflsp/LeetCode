/*****************************

Given a string s and a dictionary of words dict, add spaces in s
to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

*****************************/

#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        for(int i = 0; i < s.size(); i++){
            bool found = false;
            for(auto it = dict.begin(); it != dict.end(); it++){
                if(it->find(s.substr(i, 1)) != string::npos){
                    found = true;
                    break;
                }
            }
            if(found == false){
                return res;
            }
        }

        for(auto it = dict.begin(); it != dict.end(); it++){
            if(s.find(*it) == 0){
                if(it->size() == s.size()){
                    res.push_back(*it);
                    return res;
                }
                vector<string> sub_res = wordBreak(s.substr(it->size(), string::npos), dict);
                for(auto at = sub_res.begin(); at != sub_res.end(); at++){
                    res.push_back(*it + " " +*at);
                }
            }
        }
        return res;
    }
};
