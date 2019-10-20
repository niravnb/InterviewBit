/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

LINK: https://www.interviewbit.com/problems/first-missing-integer/
*/

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size(), j=  0;
    
    for(int i = 0; i<n;i++){
        if(A[i]<=0 || A[i] > n){
            swap(A[i],A[j++]);
        }
    }
    
    for(int i = j;i<n;i++){
        if(abs(A[i])-1+j<n && A[abs(A[i])-1+j]>0)
        A[abs(A[i])-1+j] = -A[abs(A[i])-1+j];
    }
    
    for(int i=j;i<n;i++){
        if(A[i]>0) return i-j+1;
    }
    
    return n-j+1;
    
    // int mini, maxi, res = 1, n = A.size();
    // bool first = true;
    
    // for(int i = 0; i<n;i++){
    //     if(A[i]>0 && A[i]<n){
    //         if(first){
    //             maxi = A[i];
    //             mini = A[i];
    //             first = false;
    //         }
    //     if(A[i]==res){
    //         res++;
    //         if(res==mini){
    //           res++;
    //           if(res==maxi) res++;
    //         }
    //     }
    //     if(A[i] == mini) mini++;
    //     if(A[i] == maxi) maxi++;
    //     else if(A[i]>maxi){
    //         // mini = maxi;
    //         maxi = A[i];
    //     }else if(A[i]<mini){
    //         // maxi = mini;
    //         mini = A[i];
    //     }
        
    //     }
    // }
    // return res;
}



/* 
Hint:


Note: numbers A[i]<=0 and A[i]>N ( N being the size of the array ) is not important to us since the missing positive integer will be in the range [1, N+1].

The answer will be N+1 only if all of the elements of the array are exact one occurrence of [1, N].

Creating buckets would have been an easy solution if using extra space was allowed.

An array of size N initialized to 0 would have been created.

For every value A[i] which lies in the range [1, N], its count in the array would have been incremented.

Finally, traversing the array would help to find the first array position with value 0 and that will be our answer.
However, usage of buckets is not allowed, can we use the existing array as bucket somehow?

Now, since additional space is not allowed either, the given array itself needs to be used to track it.

It may be helpful to use the fact that the size of the set we are looking to track is [1, N]

which happens to be the same size as the size of the array.

This means we can use the array to track these elements.

We traverse the array and if A[i] is in [1,N] range, we try to put in the index of same value in the array.

*/