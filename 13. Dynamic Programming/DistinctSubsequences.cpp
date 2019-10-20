/*
Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence that is identical to the sequence T.

 Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none ) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
Example :

S = "rabbbit" 
T = "rabbit"
Return 3. And the formations as follows:

S1= "ra_bbit" 
S2= "rab_bit" 
S3="rabb_it"
"_" marks the removed character.

LINK: https://www.interviewbit.com/problems/distinct-subsequences/
*/

int Solution::numDistinct(string A, string B) {
    int na = A.length();
    int nb = B.length();
    
    if(nb>na) return 0;
    
    vector<vector<int>> dp(na+1, vector<int>(nb+1,0));
    
    for(int i =0;i<=na;i++) dp[i][0] = 1;
    
    for(int i=1;i<=na;i++){
        for(int j=1;j<=nb;j++){
            dp[i][j] = dp[i-1][j];
            if(A[i-1] == B[j-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }
    
    return dp[na][nb];
}

// It's other way [i][j] = [j][i]
/**
         * Solution (DP):
         * We keep a m*n matrix and scanning through string S, while
         * m = T.length() + 1 and n = S.length() + 1
         * and each cell in matrix Path[i][j] means the number of distinct subsequences of 
         * T.substr(1...i) in S(1...j)
         * 
         * Path[i][j] = Path[i][j-1]            (discard S[j])
         *              +     Path[i-1][j-1]    (S[j] == T[i] and we are going to use S[j])
         *                 or 0                 (S[j] != T[i] so we could not use S[j])
         * while Path[0][j] = 1 and Path[i][0] = 0.
         */
