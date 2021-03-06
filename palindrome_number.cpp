/**********************************

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

**********************************/

#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int temp = x;
        int n = 0;
        while(temp != 0){
            temp = temp / 10;
            n++;
        }
        while(n > 1){
            if(x % 10 == x / (int)pow(10, n-1)){
                x = (x % (int)pow(10, n-1)) / 10;
                n = n - 2;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
