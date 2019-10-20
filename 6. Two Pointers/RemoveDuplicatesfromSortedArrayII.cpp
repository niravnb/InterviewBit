/*
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

LINK: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
*/
int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int i = 0, j = 0, c;
    
    for (; i < n; i++) { 
        if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
        else A[j++] = A[i];
    }
   
    
    // for(;i<n; i++){
    //     for(c=1; i+1<n && A[i]==A[i+1]; i++, c++);
    //     if(c>=2) A[j++] = A[i];
    //     A[j++] = A[i];
    // }
    
    A.erase(A.begin()+j, A.end());
    
    return j;
}
