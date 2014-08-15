/****************************************

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold
additional elements from B. The number of elements initialized in A and B are m and n
respectively.

****************************************/


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *C = new int[m];
        for(int i = 0; i < m; i++){
            C[i] = A[i];
        }
        int i, j;
        for(i = 0, j = 0; i < m && j < n;){
            if(C[i] < B[j]){
                A[i+j] = C[i];
                i++;
            }
            else{
                A[i+j] = B[j];
                j++;
            }
        }
        for(; i < m; i++){
            A[n + i] = C[i];
        }
        for(; j < n; j++){
            A[m + j] = B[j];
        }
    }
};
