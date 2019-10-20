/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 

LINK: https://www.interviewbit.com/problems/3-sum-zero/
*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector< vector<int> > res;
    
    for(int i = 0; i<n-2;i++){
        while(A[i] == A[i-1]) i++;
        int j = i+1;
        for(int k = n-1;k>j;){
            if(A[i]+A[j]+A[k]==0){
                res.push_back({A[i],A[j],A[k]});
                k--;
                j++;
                while(A[k] == A[k+1]) k--;
                while(A[j] == A[j-1]) j++;
            }else if(A[i]+A[j]+A[k]>0) k--;
            else j++;
        }
    }
    
    return res;
}
