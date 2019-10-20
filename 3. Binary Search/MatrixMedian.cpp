/*
Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.
Note: No extra memory is allowed.

LINK: https://www.interviewbit.com/problems/matrix-median/
*/

int Solution::findMedian(vector<vector<int> > &A) {
    int r = A.size(), c = A[0].size();
    int mx = INT_MIN, mn = INT_MAX;
    
    for(int i = 0; i<r; i++) mx = max(mx, A[i][c-1]);
    for(int i = 0; i<r; i++) mn = min(mn, A[i][0]);
    
    int desired = (1 + r*c)/2;
    while(mn<mx){
        int mid = mn + (mx - mn)/2;
        
        int c = 0;
        for(int i =0; i<r; i++){
            c += upper_bound(A[i].begin(),A[i].end(),mid) - A[i].begin();
        }
        
        if(c<desired) mn = mid+1;
        else mx = mid;
    }
    return mn;
}
