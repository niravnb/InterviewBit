/*
You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

Example :

Input : 
	S = [1, 2, 3] 
	N = 4

Return : 4

Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	
Note that the answer can overflow. So, give us the answer % 1000007

LINK: https://www.interviewbit.com/problems/coin-sum-infinite/
*/
int Solution::coinchange2(vector<int> &A, int B) {
    int n = B, m = A.size();
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i =0;i<m;i++){
        for(int j = A[i];j<=n;j++){
            dp[j]= (dp[j] + dp[j-A[i]])%1000007;
        }
    }
    
    return dp[n];
}
