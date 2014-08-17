/**************************************

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false


According to the test cases, p is the wildcard pattern...

***************************************/

#include <cstring>

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *lastStar = NULL;
        const char *lastS = NULL;
        while(*s != 0){
            if(*s == *p || *p == '?'){
                s++;
                p++;
            }
            else{
                if(*p == '*'){
                    while(*p == '*'){
                        p++;
                    }
                    if(*p == 0){
                        return true;
                    }
                    lastStar = p;
                    lastS = s;
                }
                else{
                    if(lastStar != NULL){
                        p = lastStar;
                        s = ++lastS;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        while(*p == '*'){
            p++;
        }

        return (*p == 0);
    }
};
