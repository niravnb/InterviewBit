/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example :

Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

LINK: https://www.interviewbit.com/problems/ways-to-decode/
*/

int Solution::numDecodings(string A) {
    int l = A.length();
    if(l==0 || A[0]=='0') return 0;
    
    int c = 1, n =1, nn=1;
    for(int i = l-1;i>=0;i--){
        if(A[i]=='0') c = 0;
        else if((i+1<l) && (A[i]=='2' && A[i+1]<='6' || A[i]=='1')) c = nn + n;
        else c = n;
        
        nn = n;
        n = c;
    }

        
    return c;
}


// Editorial DP
int Solution::numDecodings(string A) {
    
    int dp[A.size()+1];
    if(A.size()==0 || A[0]=='0')
        return 0;
    dp[0] =1;
    dp[1] = 1;
    
    for(int i = 2; i<A.size()+1; i++)
    {
        dp[i] = 0;
        if(A[i-1]!='0')
            dp[i] = dp[i-1];
        
        if(A[i-2]=='1')
            dp[i] += dp[i-2];
        else if(A[i-2]=='2' &&('0'<=A[i-1] && A[i-1]<='6'))
            dp[i] += dp[i-2];
    }
    return dp[A.size()];
}
