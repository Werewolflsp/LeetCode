/*******************************

Given two words (start and end), and a dictionary, find all shortest transformation
sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

*******************************/

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > res;
    unordered_map<string, vector<string> > pre;
    string start;

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        res.clear();
        unordered_set<string> q[2];
        pre.clear();
        int current = 0;
        int previous = 1;
        q[previous].insert(start);

        this->start = start;
        int length = start.size();
        dict.erase(start);
        dict.insert(end);

        while(true){
            if(q[previous].find(end) != q[previous].end()){
                break;
            }

            for(auto it = q[previous].begin(); it != q[previous].end(); it++){
                string s = *it;
                for(int m = 0; m < length; m++){
                    char save = s[m];
                    for(int i = 0; i < 26; i++){
                        s[m] = 'a' + i;
                        auto et = dict.find(s);
                        if(et != dict.end()){
                            pre[s].push_back(*it);
                            q[current].insert(s);
                        }
                    }
                    s[m] = save;
                }
            }

            if(q[current].size() == 0){
                break;
            }

            q[previous].clear();
            for(auto it = q[current].begin(); it != q[current].end(); it++){
                dict.erase(*it);
            }
            current = !current;
            previous = !previous;
    }

        vector<string> v;
        output(end, v);

        return res;
    }

    void output(const string& end, vector<string> v){
        if(pre[end].size() == 0){
            if(end == start){
                v.push_back(end);
                reverse(v.begin(), v.end());
                res.push_back(v);
            }
        }
        else{
            v.push_back(end);
            for(auto it = pre[end].begin(); it != pre[end].end(); it++){
                output(*it, v);
            }
        }
    }
};
