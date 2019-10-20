/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example,
Given:

s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/interleaving-strings/
*/
bool isInterleaving(vector<vector<int>> &dp, string &A, string &B, string &C, int i, int j){
    int n = A.length(), m = B.length(), nc = C.length();
    if(i==n && j == m){
        return true;
    }
    if(i+j>=nc) return false;
    if(dp[i][j]!=-1) return dp[i][j];
    
    bool ans =  false;
    if(i<n && A[i]==C[i+j]) ans = ans | isInterleaving(dp,A,B,C,i+1,j);
    if(j<m && B[j]==C[i+j]) ans = ans | isInterleaving(dp,A,B,C,i,j+1);
    dp[i][j] = ans;
    return ans;
}

int Solution::isInterleave(string A, string B, string C) {
    
    int n = A.length(), m = B.length(), nc = C.length();
    if(nc!=n+m) return 0;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    return isInterleaving(dp,A,B,C,0,0);
    
    // int n = A.length(), m = B.length(), nc = C.length(), i, j , k;
    // i = j = k = 0;
    // if(nc!=n+m) return 0;
    
    // vector<int> dp(m+1,0);
    
    // for(i=0;i<=n;i++){
    //     for(j=0;j<=m;j++){
    //         if(i==0 && j == 0) dp[j] = 1;
    //         else if(i==0) dp[j] = dp[j-1] && B[j-1]==C[j-1];
    //         else if(j==0) dp[j] = dp[j] && A[i-1]==C[i-1];
    //         else dp[j] = (dp[j-1] && B[j-1]==C[i+j-1]) || (dp[j] && A[i-1]==C[i+j-1]);
    //     }
    // }
    
    // return dp[m];
    
    
}
