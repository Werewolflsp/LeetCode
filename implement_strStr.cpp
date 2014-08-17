/********************************

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack,
or null if needle is not part of haystack.

********************************/

#include <cstring>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int m = 0;
        for(int i = 0; needle[i] != 0; i++){
            m++;
        }
        if(m == 0){
            return haystack;
        }
        int n = 0;
        for(int i = 0; haystack[i] != 0; i++){
            n++;
        }

        for(int i = 0; i <= n-m; i++){
            bool flag = false;
            for(int j = 0; needle[j] != 0; j++){
                flag = true;
                if(haystack[i+j] == 0 || haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return haystack + i;
            }
        }
        return NULL;
    }
};
