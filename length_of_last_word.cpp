/*************************************

Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

*************************************/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res = 0;
        int i = 0, j = -1;
        while(s[i] != 0){
            if(s[i] == ' '){
                if(i > 0 && s[i-1] != ' '){
                    res = i - 1 - j;
                }
                j = i;
            }
            i++;
        }
        while(j < 0 || s[j] == ' '){
            j++;
        }
        if(i - j > 0){
            res = i - j;
        }
        return res;
    }
};
