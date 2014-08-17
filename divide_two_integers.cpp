/****************************

Divide two integers without using multiplication, division and mod operator.

****************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = true;
        long long bei = dividend;
        long long d = divisor;
        if(bei < 0){
            flag = !flag;
            bei = -bei;
        }
        if(d < 0){
            flag = !flag;
            d = -d;
        }
        long long originalD = d;

        long long res = 0;
        int tmp = 0;
        while(bei >= d){
            tmp++;
            d = d << 1;
        }
        tmp--;
        d = d >> 1;
        while(d >= originalD){
            if(bei >= d){
                int fact = 1 << tmp;
                do{
                    bei -= d;
                    res += fact;
                }while(bei >= d);
            }
            tmp--;
            d = d >> 1;
        }

        if(!flag){
            res = -res;
        }
        return (int)res;
    }
};
