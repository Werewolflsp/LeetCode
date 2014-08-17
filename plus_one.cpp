/******************************************

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

******************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size() - 1;
        digits[n]++;
        for(int i = n; i >= 0; i--){
            if(digits[i] < 10){
                break;
            }
            else{
                digits[i] = digits[i] - 10;
                if(i > 0){
                    digits[i-1]++;
                }
                else{
                    digits.insert(digits.begin(), 1);
                }
            }
        }
        return digits;
    }
};
