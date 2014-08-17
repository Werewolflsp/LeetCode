/*****************************************

You are given a string, S, and a list of words, L, that are all of the same
length. Find all starting indices of substring(s) in S that is a concatenation
of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

******************************************/

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if(L.empty()){
            return res;
        }
        int interval = L[0].size();
        unordered_map<string, int> dict;
        for(auto it = L.begin(); it != L.end(); it++){
            dict[*it]++;
        }

        unordered_map<string, int> count;
        for(int i = 0; i <= (int)S.size()-(int)L.size()*interval; i++){
            bool flag = true;
            count.clear();
            for(int j = 0; j < L.size(); j++){
                string tmp = S.substr(i + j*interval, interval);
                count[tmp]++;
                if(count[tmp] > dict[tmp]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.push_back(i);
            }
        }
        return res;
    }
};
