/*************************************

Given n points on a 2D plane, find the maximum number of
points that lie on the same straight line.

*************************************/

#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int max = 0;
        vector<Point> lines;
        unordered_map<double, int> nums;
        for(auto iter = points.begin(); iter != points.end(); iter++){
            nums.clear();
            int sameDotCount = 0;
            int maxCount = 1;
            for(auto eter = iter + 1; eter != points.end(); eter++){
                double k;
                if(eter->x == iter->x && iter->y == eter->y){
                    sameDotCount++;
                    continue;
                }
                else if(iter->x == eter->x){
                    k = std::numeric_limits<double>::infinity();
                }
                else{
                    k = (double)(iter->y - eter->y) / (iter->x - eter->x);
                }
                if(nums.find(k) != nums.end()){
                    nums[k]++;
                }
                else{
                    nums[k] = 2;
                }
                if(nums[k] > maxCount){
                    maxCount = nums[k];
                }
            }
            maxCount += sameDotCount;
            if(maxCount > max){
                max = maxCount;
            }
        }
        return max;
    }
};
