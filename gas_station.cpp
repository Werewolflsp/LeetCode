/***************************

There are N gas stations along a circular route,where
the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs
cost[i] of gas to travel from station i to its next
station (i+1). You begin the journey with an empty
tank at one of the gas stations.

Return the starting gas station's index if you can travel
around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

***************************/

#include <vector>
using namespace std;

class Solution {
public:
    struct partial{
        int start;
        int end;
        int cost;

        partial(int a){
            start = a;
            end = -1;
            cost = 0;
        }
    };

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<partial> delta;
        int N = gas.size();
        if(N == 0){
            return -1;
        }
        delta.push_back(partial(0));
        delta.back().cost = gas[0] - cost[0];
        delta.back().end = 1%N;
        for(int i = 1; i < N; i++){
            int costNow = gas[i] - cost[i];
            int costAll = delta.back().cost + costNow;
            if((delta.back().cost >= 0 && costAll < 0) ||
                (delta.back().cost < 0 && costNow >= 0)){
                delta.push_back(partial(i));
                delta.back().cost = costNow;
            }
            else{
                delta.back().cost = costAll;
            }
            delta.back().end = (i+1)%N;
        }

        int left;
        for(int i = 0; i < delta.size(); i++){
            left = 0;
            for(int j = 0; j < delta.size(); j++){
                left += delta[(i+j)%delta.size()].cost;
                if(left < 0){
                    break;
                }
                if(j == delta.size() - 1){
                    return delta[i].start;
                }
            }
        }
        return -1;
    }
};
