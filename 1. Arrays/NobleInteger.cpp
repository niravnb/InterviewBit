/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

LINK: https://www.interviewbit.com/problems/noble-integer/
*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    
    for(int i = 0; i<n;i++){
        if(A[i]>=0){
            if(i<n-1 && A[i]==A[i+1]) continue;
            if(A[i]==n-i-1) return 1;
        }
    }
    
    return -1;
}
