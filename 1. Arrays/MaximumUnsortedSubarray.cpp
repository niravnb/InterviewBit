/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

LINK: https://www.interviewbit.com/problems/maximum-unsorted-subarray/
*/

vector<int> Solution::subUnsort(vector<int> &A) {

    int n = A.size();
    int f1 =0, f2 = 0, s = 0, e= n-1;
    
    for(int i = 1; i<n; i++){
        if(A[i]<A[i-1]){
            int j = s;
            while(j>=0 && A[j]>A[i]) j--;
            
            if(j<s) s= j+1;
            f1 = 1;
        }
        if(f1==0) s = i;
    }
    
    for(int i = n-2; i>=0; i--){
        if(A[i]>A[i+1]){
            int j = e;
            while(j<n && A[j]<A[i]) j++;
            
            if(j>e) e = j-1;
            f2=1;
        }
        if(f2==0) e = i;
    }
    
    if(f1==0 || f2==0){
        return {-1};
    }
    
    return {s,e};
}

