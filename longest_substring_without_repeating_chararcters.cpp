/**********************************

Given a string, find the length of the longest substring without repeating
characters. For example, the longest substring without repeating letters for
"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
is "b", with the length of 1.

**********************************/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int res = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(last.find(s[i]) != last.end()){
                if(res < last.size()){
                    res = last.size();
                }
                for(int j = start; j < last[s[i]]; j++){
                    last.erase(s[j]);
                }
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        if(res < last.size()){
            res = last.size();
        }
        return res;
    }
};
