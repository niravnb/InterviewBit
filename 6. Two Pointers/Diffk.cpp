/*
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.

LINK: https://www.interviewbit.com/problems/diffk/
*/
int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size(), i = 0, j = 1;
    if(n<2) return 0;
    
    while(i<n && j<n){
        if(i!=j && A[j]-A[i]==B) return 1;
        else if (A[j]-A[i]>B) i++;
        else j++;
    }
    
    return 0;
    
    
    
    // O(n^2)
    // int n = A.size(), i = 0, j = n-1;
    // for(int ind =0; ind<n; ind++){
    //     j = n-1;
    //     i = ind;
    //     while(i<j){
    //     if(A[j]-A[i]==B) return 1;
    //     else if (A[j]-A[i]>B) j--;
    //     else i++;
    //     }
    // }
    // return 0;
}

// Using Binary search
// int Solution::diffPossible(vector<int> &A, int B)
// {
//     int n=A.size();
 
//     for(int i=0;i<n-1;i++)
//     {
//         int l=i+1;
//         int r=n-1;
//         int x=B+A[i];
//         while(l<=r)
//         {
//             int mid = (l+r)/2;
//             if(A[mid]==x)
//                 return 1;
//             if(A[mid]<x)
//                 l=mid+1;
//             else
//                 r=mid-1;
//         }
//     }
//     return 0;
// }