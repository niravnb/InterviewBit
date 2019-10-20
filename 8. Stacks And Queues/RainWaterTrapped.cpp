/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Rain water trapped: Example 1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

LINK: https://www.interviewbit.com/problems/rain-water-trapped/
*/

int Solution::trap(const vector<int> &A) {
    int n = A.size(), res  = 0;
    vector<int> l(n,0),r(n,0);
    l[0] = A[0];
    r[n-1] = A[n-1];
    
    for(int i = 1;i<n;i++) l[i] = max(l[i-1],A[i]);
    for(int i = n-2;i>=0;i--) r[i] = max(r[i+1],A[i]);
    
    for(int i = 0;i<n;i++){
        res += min(l[i],r[i])-A[i];
    }
    
    return res;
}
