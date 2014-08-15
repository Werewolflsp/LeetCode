/***********************************

Given two words (start and end), and a dictionary, find the length of shortest
transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

************************************/

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> q[2];
        int current = 0;
        int previous = 1;
        q[previous].insert(start);

        int length = start.size();
        dict.erase(start);
        dict.insert(end);

        int n = 1;

        while(true){
            if(q[previous].find(end) != q[previous].end()){
                return n;
            }

            for(auto it = q[previous].begin(); it != q[previous].end(); it++){
                string s = *it;
                for(int m = 0; m < length; m++){
                    char save = s[m];
                    for(int i = 0; i < 26; i++){
                        s[m] = 'a' + i;
                        auto et = dict.find(s);
                        if(et != dict.end()){
                            q[current].insert(s);
                        }
                    }
                    s[m] = save;
                }
            }

            if(q[current].size() == 0){
                return 0;
            }

            q[previous].clear();
            for(auto it = q[current].begin(); it != q[current].end(); it++){
                dict.erase(*it);
            }
            current = !current;
            previous = !previous;

            n++;
        }
    }
};
