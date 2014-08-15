/*****************************************

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions
as you like (ie, buy one and sell one share of the stock multiple times). However, you
may not engage in multiple transactions at the same time (ie, you must sell the stock
before you buy again).

*****************************************/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2){
            return 0;
        }
        int res = 0;
        int buyDay = -1;
        bool bought = false;
        if(prices[0] < prices[1]){
            buyDay = 0;
            bought = true;
        }
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < prices[i-1]){
                if(bought){
                    res += prices[i-1] - prices[buyDay];
                    bought = false;
                }
            }
            else if(prices[i] > prices[i-1]){
                if(i != prices.size() - 1){
                    if(!bought){
                        bought = true;
                        buyDay = i-1;
                    }
                }
                else{
                    if(bought){
                        res += prices[i] - prices[buyDay];
                    }
                    else{
                        res += prices[i] - prices[i-1];
                    }
                }
            }
            else{
                if(i == prices.size() - 1 && bought){
                    res += prices[i] - prices[buyDay];
                }
            }
        }
        return res;
    }
};
