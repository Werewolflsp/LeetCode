/*****************************************

Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

******************************************/

// Used radix sort, might redo this

#include <vector>
using namespace std;

class Solution {
public:
    void radixSortPositive(int A[], int n, int max){
        if(n == 0){
            return;
        }

        int exp = 1;
        int *b = new int[n];

        while(max/exp > 0){
            int bucket[10] = {0};
            for(int i = 0; i < n; i++){
                bucket[(A[i]/exp) % 10]++;
            }
            for(int i = 1; i < 10; i++){
                bucket[i] += bucket[i-1];
            }
            for(int i = n-1; i >= 0; i--){
                b[--bucket[(A[i]/exp) % 10]] = A[i];
            }
            for(int i = 0; i < n; i++){
                A[i] = b[i];
            }

            exp = exp * 10;
        }
        delete[] b;
        b = NULL;
    }

    void radixsort(vector<int>& A, int n){
        int positive = 0, negative = 0;
        int maxp = 0; //最大的正数
        int maxn = 0; //绝对值最大的负数

        for(int i = 0; i < n; i++){
            if(A[i] >= 0){
                positive++;
                if(A[i] > maxp){
                    maxp = A[i];
                }
            }
            else{
                negative++;
                if(A[i] < maxn){
                    maxn = A[i];
                }
            }
        }

        int *Ap = NULL, *An = NULL;
        if(positive > 0){
            Ap = new int[positive];
        }
        if(negative > 0){
            An = new int[negative];
        }

        int j = 0, k = 0;
        for(int i = 0; i < n; i++){
            if(A[i] >= 0){
                Ap[j] = A[i];
                j++;
            }
            else{
                if(A[i] > INT_MIN){
                    An[k] = -A[i];
                }
                else{
                    An[k] = 0;
                    maxn = -INT_MAX;
                }
                k++;
            }
        }

        radixSortPositive(Ap, positive, maxp);
        radixSortPositive(An, negative, -maxn);

        for(int k = negative-1; k >= 0; k--){
            if(An[k] > 0){
                A[negative-k-1] = -An[k];
            }
            else{
                A[negative-k-1] = INT_MIN;
            }
        }
        delete[] An;
        An = NULL;

        for(int j = 0; j < positive; j++){
            A[negative+j] = Ap[j];
        }
        delete[] Ap;
        Ap = NULL;
    }

    int longestConsecutive(vector<int> &num) {
        radixsort(num, num.size());
        int max = 1;
        int temp = 1;
        for(int i = 1; i < num.size(); i++){
            if(num[i] - num[i-1] == 1){
                temp++;
                if(temp > max){
                    max = temp;
                }
            }
            else if(num[i] == num[i-1]){
                continue;
            }
            else{
                temp = 1;
            }
        }
        return max;
    }
};
