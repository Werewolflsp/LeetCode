/******************************

Given an array of integers, every element appears three times except for one.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?

******************************/

// Two unperfect solutions
// bit add and mode 3 will be better
// Will redo this when I'm in the mood

#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> count;
        for(int i = 0; i < n; i++){
            count[A[i]]++;
        }
        for(auto it = count.begin(); it != count.end(); it++){
            if(it->second != 3){
                return it->first;
            }
        }
        return 0;
    }
};

// Used a radix sort
class Solution2 {
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

    void radixsort(int A[], int n){
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

    int singleNumber(int A[], int n) {
        if(n == 1){
            return A[0];
        }
        radixsort(A, n);
        int count = 1;
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]){
                count++;
            }
            else{
                if(count != 3){
                    return A[i-1];
                }
                else{
                    count = 1;
                }
            }
        }
        return A[n-1];
    }
};
