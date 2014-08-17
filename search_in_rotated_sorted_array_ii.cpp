/****************************************************************

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

****************************************************************/

class Solution {
public:
    bool search(int A[], int n, int target) {
        return search(A, 0, n-1, target);
    }

    bool search(int A[], int s, int e, int target){
        if(s > e){
            return false;
        }
        else{
            int index = (s + e) / 2;
            bool res = false;
            if(A[index] == target){
                return true;
            }
            else if(A[index] < target){
                res = search(A, index + 1, e, target);
                if(!res){
                    res = search(A, s, index - 1, target);
                }
            }
            else{
                res = search(A, s, index - 1, target);
                if(!res){
                    res = search(A, index + 1, e, target);
                }
            }
            return res;
        }
    }
};
