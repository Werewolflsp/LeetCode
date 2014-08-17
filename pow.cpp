/***************************

Implement pow(x, n).

***************************/

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0){
            return 1.0 / pow_unsigned(x, (unsigned int)(-(double)n));
        }
        if(n == 0){
            return 1.0;
        }
        else if(n == 1){
            return x;
        }

        return pow_unsigned(x, n);
    }

    double pow_unsigned(double x, unsigned int n){
        int left = n % 2;
        double res = x;
        n = n / 2;
        res = res * res;
        res = pow(res, n);
        if(left == 1){
            res = res * x;
        }

        return res;
    }
};
