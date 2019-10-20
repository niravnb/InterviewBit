/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example : 
Given 
s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

LINK: https://www.interviewbit.com/problems/palindrome-partitioning-ii/
*/
int Solution::minCut(string A) {
    int n = A.length();
    int dp[n];
    bool pal[n][n];
    
    for(int i =0;i<n;i++) pal[i][i] = true;
    
    for(int l =2;l<=n;l++){
        for(int i = 0; i<=n-l;i++){
            int j = i+l-1;
            if(l==2) pal[i][j] = (A[i]==A[j]);
            else pal[i][j] = (A[i]==A[j]) && pal[i+1][j-1];
        }
    }
    
    for(int i = 0; i<n;i++){
        if(pal[0][i]) dp[i] = 0;
        else{
            dp[i] = INT_MAX;
            for(int j=1;j<=i;j++){
                if(pal[j][i] && dp[i]>(1+dp[j-1])) dp[i] = 1 + dp[j-1];
            }
        }
    }
    
    return dp[n-1];
}
