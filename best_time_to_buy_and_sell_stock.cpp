/**********************************

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell
one share of the stock), design an algorithm to find the maximum profit.

**********************************/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2){
            return 0;
        }
        int res = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            res = max(prices[i]-minPrice, res);
        }
        return res;
    }
};
