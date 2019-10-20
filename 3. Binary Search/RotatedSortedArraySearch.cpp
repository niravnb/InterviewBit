/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

LINK: https://www.interviewbit.com/problems/rotated-sorted-array-search/
*/

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int index = -1, n = A.size();
    int l = 0, r = n-1, m;
    
    while(l<=r){
        m = l + (r-l)/2;
        if(A[m]==B) return m;
        if(A[m]<=A[r]){
            if(B > A[m] && B <= A[r]) l = m +1;
            else r = m-1;
        }else if(A[l]<=A[m]){
            if(B>=A[l] && B < A[m]) r = m-1;
            else l = m +1;
        }
        
    }
    
    return index;
    
}
