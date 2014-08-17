/********************************************

Given a string S and a string T, find the minimum window in S which will contain
all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy
string "".

If there are multiple such windows, you are guaranteed that there will always be
only one unique minimum window in S.

********************************************/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.size() < T.size()){
            return "";
        }

        unordered_map<char, int> expect;
        unordered_map<char, int> found;
        int count = 0;
        int maxStart = 0, minEnd = S.size();
        for(int i = 0; i < T.size(); i++){
            expect[T[i]]++;
        }
        for(int start = 0, i = 0; i < S.size(); i++){
            if(expect.find(S[i]) != expect.end()){
                found[S[i]]++;
                if(found[S[i]] <= expect[S[i]]){
                    count++;
                }
                if(count == T.size()){
                    do{
                        if(expect.find(S[start]) != expect.end()){
                            found[S[start]]--;
                            if(found[S[start]] < expect[S[start]]){
                                count--;
                            }
                            if(count < T.size()){
                                if((i - start) < (minEnd - maxStart)){
                                    maxStart = start;
                                    minEnd = i;
                                }
                                start++;
                                break;
                            }
                        }
                        start++;
                    }while(start <= i);
                }
            }
        }

        if(minEnd == S.size()){
            return "";
        }

        return S.substr(maxStart, minEnd-maxStart+1);
    }
};
