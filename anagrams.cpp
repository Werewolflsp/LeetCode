/*******************************

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

*******************************/

#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;

        map<vector<int>, int> data;
        for(auto it = strs.begin(); it != strs.end(); it++){
            vector<int> count(26, 0);
            for(int i = 0; i < it->size(); i++){
                count[(*it)[i]-'a']++;
            }
            if(data.find(count) == data.end()){
                data[count] = it - strs.begin();
            }
            else{
                if(data[count] >= 0){
                    res.push_back(strs[data[count]]);
                    data[count] = -1;
                }
                res.push_back(*it);
            }
        }

        return res;
    }
};
