/*
Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

**

N = 2, S = 4 
Valid numbers are {22, 31, 13, 40} 
Hence output 4.

LINK: https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
*/

#define MOD 1000000007

int count(int n, int s,  vector<vector<int>> &dp){
    if(n==0) return s==0;
    
    if(dp[n][s] != -1) return dp[n][s];
    
    // if(n==1 && s>=0 && s<10) dp[n][s] = 1;
    // else{
        long ans = 0;
        for(int i =0; i<10; i++){
            if(s-i>=0) ans =  (ans + count(n-1,s-i,dp)%MOD)%MOD; 
        }
        dp[n][s] = ans;
    // }
    
    return dp[n][s];
}

int Solution::solve(int A, int B) {

    if(A==0) return 0;
    if(A==1 && (B>=0 && B<10)) return 1;
    
    vector<vector<int>> dp(A+1,vector<int>(B+1,-1));
    
    long ans = 0;
    for(int i = 1; i<=9; i++){
        if(B-i>=0) ans = (ans + count(A-1,B-i,dp)%MOD)%MOD; 
    }
    return ans;
}
