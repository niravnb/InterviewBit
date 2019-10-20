/*
Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert i.

LINK: https://www.interviewbit.com/problems/edit-distance/
*/
int Solution::minDistance(string A, string B) {
    
        string word1 = A, word2 = B;
        int m = word1.length(), n = word2.length();
        
        if(m==0) return n;
        if(n==0) return m;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for(int i =0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        return dp[m][n];
        
}
