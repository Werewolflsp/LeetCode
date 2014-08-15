/********************************

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock
before you buy again).

********************************/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2){
            return 0;
        }
        int res = 0;
        int n = prices.size();

        int minPrice = prices[0];
        int *firstDrop = new int[n];
        int maxPrice = prices[n-1];
        int *secondDrop = new int[n];
        firstDrop[0] = 0;
        secondDrop[n-1] = 0;
        for(int i = 1; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            firstDrop[i] = max(prices[i] - minPrice, firstDrop[i-1]);
            maxPrice = max(maxPrice, prices[n-1-i]);
            secondDrop[n-1-i] = max(maxPrice - prices[n-1-i], secondDrop[n-i]);
        }
        for(int i = 0; i < n-1; i++){
            res = max(res, firstDrop[i]+secondDrop[i+1]);
        }
        res = max(res, firstDrop[n-1]);

        delete[] firstDrop;
        delete[] secondDrop;

        return res;
    }
};
