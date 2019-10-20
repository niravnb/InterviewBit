/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Examples :

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "*") → 1
isMatch("aa", "a*") → 1
isMatch("ab", "?*") → 1
isMatch("aab", "c*a*b") → 0
Return 1/0 for this problem.

LINK: https://www.interviewbit.com/problems/regular-expression-match/
*/
int Solution::isMatch(const string s, const string p) {
    int ns = s.length();
    int np = p.length();
    
    vector<vector<bool>> dp(np+1, vector<bool>(ns+1,false));
    dp[0][0] = true;
    for(int i = 1; i<=np;i++) if(p[i-1]=='*') dp[i][0] = dp[i-1][0];
    
    for(int r = 1; r<=np;r++){
        for(int c=1; c<=ns;c++){
            if(p[r-1]=='?' || p[r-1]==s[c-1]) dp[r][c] = dp[r-1][c-1];
            else if(p[r-1]=='*') dp[r][c] = dp[r-1][c] || dp[r][c-1];
        }
    }
    
    return dp[np][ns];
}

}