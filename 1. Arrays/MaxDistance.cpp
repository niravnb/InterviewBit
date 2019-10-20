/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

LINK: https://www.interviewbit.com/problems/max-distance/
*/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    vector<pair<int,int>> arr;
    
    for(int i = 0; i<n; i++) arr.push_back({A[i],i});
    sort(arr.begin(),arr.end());
    
    int res = 0, maxInd = arr[n-1].second;
    
    for(int i = n-2; i>=0; i--){
        res = max(res, maxInd - arr[i].second);
        maxInd = max(maxInd, arr[i].second);
    }
    
    return res;
    
    
    
    // int n = A.size();
    // vector<int> Lmin(n), Rmax(n);
    // Lmin[0] = A[0];
    // Rmax[n-1] = A[n-1];
    
    // for(int i = 1; i<n; i++) Lmin[i] = min(A[i], Lmin[i-1]);
    // for(int i = n-2; i>=0 ; i--) Rmax[i] = max(A[i], Rmax[i+1]);
    
    // int i = 0, j = 0, res = -1;
    // while(i<n && j<n){
    //     if(Lmin[i]<=Rmax[j]){
    //         res = max(res, j-i);
    //         j++;
    //     }else i++;
    // }
    
    // return res;
}
