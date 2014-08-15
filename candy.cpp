/*************************************

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

*************************************/

#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> given;
        for(auto it = ratings.begin(); it != ratings.end(); it++){
            given.push_back(1);
        }
        bool needMore = true;
        while(needMore){
            needMore = false;
            for(auto it = ratings.begin(), et = given.begin();
                it != ratings.end(); it++, et++){
                if(it != ratings.begin()){
                    if((*it > *(it-1) && *et <= *(et-1))){
                        *et = *(et-1) + 1;
                    }
                    else if((*it < *(it-1) && *et >= *(et-1))){
                        *(et-1) = *et + 1;
                        needMore = true;
                        break;
                    }
                }
            }
        }
        int res = 0;
        for(auto it = given.begin(); it != given.end(); it++){
            res += *it;
        }
        return res;
    }
};
