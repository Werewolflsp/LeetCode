/****************************************

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

****************************************/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0){
            return 0;
        }
        int *a = new int[n];
        a[0] = 1;
        for(int i = 1; i < n; i++){
            if(i == 1){
                a[i] = a[0] + 1;
            }
            else{
                a[i] = a[i-1] + a[i-2];
            }
        }
        int res = a[n-1];
        delete[] a;
        return res;
    }
};
