/**************************************

Given a string, determine if it is a palindrome, considering only alphanumeric
characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to
ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

**************************************/

#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int delta = 'A' - 'a';
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            if(!isLetter(s[i])){
                j++;
                continue;
            }
            if(!isLetter(s[j])){
                i--;
                continue;
            }
            if(s[i] != s[j] && s[i] != s[j] - delta && s[i] != s[j] + delta){
                return false;
            }
        }
        return true;
    }

    bool isLetter(char a){
        return (a >= 'a' && a <= 'z') || (a >= 'A' && a <='Z') || (a >= '0' && a <= '9');
    }
};
