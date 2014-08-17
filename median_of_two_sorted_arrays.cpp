/**********************************

There are two sorted arrays A and B of size m and n respectively. Find the median
of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**********************************/

#include <climits>
#include <cassert>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int temp = m + n;
        if(temp % 2 != 0){
            return findKthSmallest(A, m, B, n, temp / 2 + 1);
        }
        else{
            return 0.5 * (findKthSmallest(A, m, B, n, temp / 2) +
                            findKthSmallest(A, m, B, n, temp / 2 + 1));
        }
    }

    int findKthSmallest(int A[], int m, int B[], int n, int k) {
        int i = (int)((double)m / (m+n) * (k-1));
        int j = (k-1) - i;
        // invariant: i + j = k-1
        // Note: A[-1] = -INF and A[m] = +INF to maintain invariant
        int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
        int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
        int Ai   = ((i == m) ? INT_MAX : A[i]);
        int Bj   = ((j == n) ? INT_MAX : B[j]);

        if (Bj_1 <= Ai && Ai <= Bj)
            return Ai;
        else if (Ai_1 <= Bj && Bj <= Ai)
            return Bj;

        assert((Ai > Bj && Ai_1 > Bj) || (Ai < Bj && Ai < Bj_1));

        // if none of the cases above, then it is either:
        if (Ai < Bj)
            // exclude Ai and below portion
            // exclude Bj and above portion
            return findKthSmallest(A+i+1, m-i-1, B, j, k-i-1);
        else /* Bj < Ai */
            // exclude Ai and above portion
            // exclude Bj and below portion
            return findKthSmallest(A, i, B+j+1, n-j-1, k-j-1);
    }
};
