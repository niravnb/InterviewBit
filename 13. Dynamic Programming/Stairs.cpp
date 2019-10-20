/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example :

Input : 3
Return : 3

Steps : [1 1 1], [1 2], [2 1]

LINK: https://www.interviewbit.com/problems/stairs/
*/

int Solution::climbStairs(int A) {
    
    vector<int> dp(A+1,0);
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    
    for(int i = 3; i<=A; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[A];
    
}
