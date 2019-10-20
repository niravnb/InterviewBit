/*
There are N coins (Assume N is even) in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first.

Write a program which computes the maximum amount of money you can win.

Example:

suppose that there are 4 coins which have value
1 2 3 4
now you are first so you pick 4
then in next term
next person picks 3 then
you pick 2 and
then next person picks 1
so total of your money is 4 + 2 = 6
next/opposite person will get 1 + 3 = 4
so maximum amount of value you can get is 6

LINK: https://www.interviewbit.com/problems/coins-in-a-line/
*/
int solve(vector<int> &A,vector<vector<int>> &dp, int i, int j){
    if(i==j) return A[i];
    if(i+1==j) return max(A[i],A[j]);
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int oneway = min(solve(A,dp,i+2,j), solve(A,dp,i+1,j-1));
    int secondway = min(solve(A,dp,i,j-2), solve(A,dp,i+1,j-1));
    
    int ans = max(A[i] + oneway, A[j] + secondway);
    // cout << oneway << " " << secondway << " " << ans << endl;
    return dp[i][j] = ans;
    
}

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    if(n==0) return 0;
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    return solve(A,dp,0,n-1);
}
