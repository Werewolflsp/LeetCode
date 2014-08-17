/**********************************

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

[A phone image here]

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you
want.

**********************************/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0){
            res.push_back("");
        }
        else if(digits.size() == 1){
            res.resize(3);
            switch (digits[0]){
                case '2':
                    res[0] = "a";
                    res[1] = "b";
                    res[2] = "c";
                    break;
                case '3':
                    res[0] = "d";
                    res[1] = "e";
                    res[2] = "f";
                    break;
                case '4':
                    res[0] = "g";
                    res[1] = "h";
                    res[2] = "i";
                    break;
                case '5':
                    res[0] = "j";
                    res[1] = "k";
                    res[2] = "l";
                    break;
                case '6':
                    res[0] = "m";
                    res[1] = "n";
                    res[2] = "o";
                    break;
                case '7':
                    res[0] = "p";
                    res[1] = "q";
                    res[2] = "r";
                    res.push_back("s");
                    break;
                case '8':
                    res[0] = "t";
                    res[1] = "u";
                    res[2] = "v";
                    break;
                case '9':
                    res[0] = "w";
                    res[1] = "x";
                    res[2] = "y";
                    res.push_back("z");
                    break;
                default:
                    break;
            }
        }
        else{
            vector<string> one = letterCombinations(digits.substr(0, 1));
            vector<string> two = letterCombinations(digits.substr(1, string::npos));
            for(auto it = one.begin(); it != one.end(); it++){
                for(auto et = two.begin(); et != two.end(); et++){
                    res.push_back(*it + *et);
                }
            }
        }
        return res;
    }
};
