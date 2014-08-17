/*******************************

Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*******************************/

#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        for(int i = num.size()-1; i >= 0; i--){
            if(i > 0 && num[i-1] < num[i]){
                int swap = i;
                for(int j = i + 1; j < num.size(); j++){
                    if(num[j] > num[i-1]){
                        swap = j;
                    }
                    else{
                        break;
                    }
                }
                int temp = num[i-1];
                num[i-1] = num[swap];
                num[swap] = temp;
                sort(num.begin()+i, num.end());
                return;
            }
        }
        for(int i = 0; i < num.size() / 2; i++){
            int temp = num[i];
            num[i] = num[num.size()-1-i];
            num[num.size()-1-i] = temp;
        }
    }
};
