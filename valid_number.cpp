/*********************************

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should
gather all requirements up front before implementing one.

*********************************/

class Solution {
public:
    bool isNumber(const char *s) {
        int i = 0;
        while(s[i] != 0){
            i++;
        }
        int n = i;
        i = 0;
        while(i < n){
            if(s[i] == ' '){
                i++;
            }
            else{
                break;
            }
        }
        int start = i;
        i = n-1;
        while(i > start){
            if(s[i] == ' '){
                i--;
            }
            else{
                break;
            }
        }
        int end = i;

        i = start;
        bool e = false;
        bool dot = false;
        bool digit = false;
        while(i <= end){
            if(s[i] == ' '){
                return false;
            }
            else if(s[i] == '-' || s[i] == '+'){
                if(i == start){
                    start++;
                }
                else if(s[i-1] != 'e' || i == end){
                    return false;
                }
            }
            else if(s[i] == 'e'){
                if(e){
                    return false;
                }
                e = true;
                if(!(i > start && i < end && ((s[i-1] >= '0' && s[i-1] <= '9') ||
                                              s[i-1] == '.' && digit) &&
                    ((s[i+1] >= '0' && s[i+1] <= '9') || s[i+1] == '+' || s[i+1] == '-'))){
                    return false;
                }
            }
            else if(s[i] == '.'){
                if(dot || e){
                    return false;
                }
                dot = true;
                if(!((i > start && i < end &&
                      ((s[i-1] >= '0' && s[i-1] <= '9') || s[i-1] == 'e') &&
                      ((s[i+1] >= '0' && s[i+1] <= '9') || s[i+1] == 'e')) ||
                     (i == start && i < end && ((s[i+1] >= '0' && s[i+1] <= '9') ||
                                                s[i+1] == 'e')) ||
                    (i > start && i == end && ((s[i-1] >= '0' && s[i-1] <= '9'))))){
                    return false;
                }
            }
            else if(s[i] < '0' || s[i] > '9'){
                return false;
            }
            else{
                digit = true;
            }
            i++;
        }

        return end >= start;
    }
};
