/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1

LINK: https://www.interviewbit.com/problems/min-sum-path-in-matrix/
*/
int Solution::minPathSum(vector<vector<int> > &A) {
        vector<vector<int> > grid = A;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,0));
        
        dp[m-1][n-1] = grid[m-1][n-1]; 
        for(int i = n-2; i>=0;i--) dp[m-1][i] = grid[m-1][i] + dp[m-1][i+1];
        
        for(int i = m-2; i>=0; i--) dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
        
        for(int i = m-2; i>=0;i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
            }
        }
        
        return dp[0][0];
}
