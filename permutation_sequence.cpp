/***************************************

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

***************************************/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        vector<int> factorial;
        factorial.push_back(1);
        string res(n, '0');
        for(int i = 1; i <= n; i++){
            num.push_back(i);
            factorial.push_back(i*factorial.back());
        }
        k--;
        for(int i = 0; i < n; i++){
            int index = k / factorial[n-i-1];
            res[i] += num[index];
            num.erase(num.begin() + index);
            k = k % factorial[n-i-1];
        }

        return res;
    }
};
