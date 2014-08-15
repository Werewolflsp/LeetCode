/*****************************

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

***************************/

class Solution {
public:
    int numTrees(int n) {
        int *a = new int[n+1];
        a[0] = 1;
        for(int i = 1; i <= n; i++){
            a[i] = 0;
            for(int j = 1; j <= i; j++){
                a[i] += a[j-1] * a[i-j];
            }
        }

        int res = a[n];
        delete[] a;
        return res;
    }
};
