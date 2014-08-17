/*************************************

Implement int sqrt(int x).

Compute and return the square root of x.

*************************************/

class Solution {
public:
    int sqrt(int x) {
        double g=x;
        while((g*g-x)>0.00001)
        {
            g=(g+x/g)/2;
        }
        return (int)g;
    }
};
