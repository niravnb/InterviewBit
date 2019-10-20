/*
Given a 2 * N Grid of numbers, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Example:

Grid:
	1 2 3 4
	2 3 4 5
so we will choose
3 and 5 so sum will be 3 + 5 = 8


Note that you can choose more than 2 numbers

LINK: https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
*/

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n,0);
    dp[0] = max(A[0][0], A[1][0]);
    
    for(int i = 1;i<n;i++){
        int curr = max(A[0][i], A[1][i]);
        if(i-2>=0) dp[i] = max(curr, max(curr + dp[i-2], dp[i-1]));
        else dp[i] = max(curr, dp[i-1]);
    }
    
    return dp[n-1];
    
}

// int Solution::adjacent(vector<vector<int> > &A)
// {
//     int n = A[0].size();
//     if(n==0)
//         return 0;
 
//     int prevInc = max(A[0][0], A[1][0]);
//     int prevExc = 0;
 
//     for(int i=1;i<n;i++)
//     {
//         int temp = max(prevInc, prevExc);
 
//         prevInc = prevExc + max(A[0][i], A[1][i]);
//         prevExc = temp;
//     }
 
//     return max(prevInc, prevExc);
// }