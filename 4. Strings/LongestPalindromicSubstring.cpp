/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

LINK: https://www.interviewbit.com/problems/longest-palindromic-substring/
*/
string Solution::longestPalindrome(string s) {
    
    int maxlen = 1, start = 0, low, high;
    int len = s.length();
 
    for(int i=0;i<len;i++)
    {
        low = i-1;
        high = i;
 
        while(low>=0 && high<len && s[low]==s[high])
        {
            if((high-low+1) > maxlen || ((high-low+1)==maxlen && low<start))
            {
                start = low;
                maxlen = (high-low+1);
            }
            low--;
            high++;
        }
 
        low = i-1;
        high = i+1;
 
        while(low>=0 && high<len && s[low]==s[high])
        {
            if((high-low+1) > maxlen || ((high-low+1)==maxlen && low<start))
            {
                start = low;
                maxlen = (high-low+1);
            }
            low--;
            high++;
        }
    }
 
    return s.substr(start,maxlen);   
    
    // DP Approach
    // int n = A.length();
    // if(n==1) return A;
    
    // vector<vector<bool>> dp(n, vector<bool>(n,false));
    // // memset(dp, false, sizeof(dp));
    
    // int len = 1, resindex = 0;
    
    // for(int i =0;i<n;i++){
    //     dp[i][i] = true;
    // }
    
    // for(int i =0;i<n-1;i++){
    //     if(A[i]==A[i+1]){
    //         dp[i][i+1] = true;
    //         if(2>len){
    //             len = 2;
    //             resindex = i;
    //         }
    //     }
    // }
    
    // for(int k = 3;k<=n;k++){
    //     for(int i = 0; i<=n-k;i++){
    //         int j = i+k-1;
            
    //         if(A[i]==A[j] && dp[i+1][j-1] == true){
    //             dp[i][j] = true;
    //             if(k>len){
    //                 len = k;
    //                 resindex = i;
    //                 // cout << k << " " << i << endl;
    //             }
    //         }
    //     }
    // }
    
    // // cout << resindex << " " << len;
    // string ret;
    // for(int i = 0; i<len;i++)
    //     ret.push_back(A[resindex+i]);
    // return ret;
    
}


// Mancher's Algorithm O(N)

string preprocess(string s){
    string ret = "#";
    for(int i = 0; i<s.length(); i++){
        ret += s[i];
        ret += "#";
    }
    return ret;
}

string Solution::longestPalindrome(string s) {
    
    string st = preprocess(s);
    
    vector<int> p(st.length(),0);
    
    int C = 0, R = 0;
    for(int i = 1; i<st.length(); i++){
        int mirr = 2*C - i;
        
        if(i < R) p[i] = min(R-i, p[mirr]);
        
        while( i + (p[i]+1)<st.length() &&  i - (1+p[i])>= 0 && st[i + (p[i]+1)] == st[i - (1+p[i])]) p[i]++;
        
        if(i + p[i]> R){
            C = i;
            R = i + p[i];
        }
    }
    C = 0;
    int mx = 0;
    for(int i = 0; i<st.length(); i++){
        if(p[i]>mx){
            mx = p[i];
            C = i;
        }
    }
    
    string res;
    string tmp = st.substr((C-p[C]),2*p[C]);
    for(int i = 0; i<tmp.length(); i++) if(tmp[i]!='#') res += tmp[i];
    return res;

}


