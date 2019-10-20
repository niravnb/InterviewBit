/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

LINK: https://www.interviewbit.com/problems/sorted-insert-position/
*/

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int l = 0, r = n-1;
    int mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(A[mid]==B) return mid;
        if(B > A[mid]){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return l;

 // return upper_bound(A.begin(), A.end(),B-1) - A.begin();

}
