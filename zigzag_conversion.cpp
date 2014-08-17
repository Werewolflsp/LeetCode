/**********************************

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number
of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

**********************************/

#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1){
            return s;
        }
        string res;
        for(int i = 0; i < nRows; i++){
            int j = i;
            bool flip = true;
            while(j < s.size()){
                res += string(1, s[j]);
                if(i == 0 || i == nRows-1){
                    j += 2 * nRows - 2;
                }
                else{
                    if(flip){
                        j += 2 * nRows - 2 - 2 * i;
                    }
                    else{
                        j += 2 * i;
                    }
                    flip = !flip;
                }
            }
        }
        return res;
    }
};
