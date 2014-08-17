/**********************************

Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

**********************************/

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0){
        }
        else if(n == 1){
            res.push_back("()");
        }
        else{
            vector<string> temp = generateParenthesis(n-1);
            unordered_set<string> setRes;
            for(auto it = temp.begin(); it != temp.end(); it++){
                size_t size = it->size();
                for(size_t i = 0; i <= size;){
                    string oneTmp = *it;
                    oneTmp.insert(i, "(");
                    for(size_t j = i+1; j <= size+1 && j > 0; j++){
                        string oneRes = oneTmp;
                        oneRes.insert(j, ")");
                        setRes.insert(oneRes);
                        j = oneTmp.find('(', j);
                    }
                    i = it->find_first_not_of('(', i+1);
                                        if(i + 1 == 0){
                                                setRes.insert(*it+"()");
                                        }
                }
            }
            for(auto it = setRes.begin(); it != setRes.end(); it++){
                res.push_back(*it);
            }
        }
        return res;
    }
};
