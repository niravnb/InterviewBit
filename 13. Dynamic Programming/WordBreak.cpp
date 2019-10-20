/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = ["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/word-break/
*/

bool wb(vector<int> &dp, unordered_set<string> &D, string &A, int s, int e){

    if(s>=e) return true;
    
    if(dp[s]!=-1) return dp[s];
    
    string tmp;
    bool tm = false;
    for(int i = s; i<e && !tm;i++){
        tmp.push_back(A[i]);
        if(D.find(tmp)!=D.end())
            tm = tm || wb(dp,D,A,i+1,e);
    }
    
    return dp[s] = tm;
   
    
}

int Solution::wordBreak(string A, vector<string> &B) {
    
    unordered_set<string> D;
    int n = B.size();
    if(n==0) return 0;

    for(auto s:B) D.insert(s);
    
    vector<int> dp(A.length(),-1);
    
    return wb(dp,D,A,0,A.length());
}
