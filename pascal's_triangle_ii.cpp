/**************************************

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

***************************************/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            res.push_back((int)((long long)res.back() * (rowIndex - i + 1) / i));
        }
        return res;
    }
};
