/************************************

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*************************************/

class Solution {
public:
    int search(int A[], int n, int target) {
        return search(A, 0, n-1, target);
    }

    int search(int A[], int s, int e, int target){
        if(s > e){
            return -1;
        }
        else{
            int index = (s + e) / 2;
            int res = -1;
            if(A[index] == target){
                return index;
            }
            else if(A[index] < target){
                res = search(A, index + 1, e, target);
                if(res == -1){
                    res = search(A, s, index - 1, target);
                }
            }
            else{
                res = search(A, s, index - 1, target);
                if(res == -1){
                    res = search(A, index + 1, e, target);
                }
            }
            return res;
        }
    }
};
