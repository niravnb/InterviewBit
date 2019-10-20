/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is

[
  "cat sand dog", 
  "cats and dog"
]
Make sure the strings are sorted in your result.

LINK: https://www.interviewbit.com/problems/word-break-ii/
*/
vector<int> dp;
vector<string> res;
unordered_set<string> st;
    
int solve(int s, int e, string &A, string str){
    if(s>=e){
        res.push_back(str);
        return 1;
    }
    
    if(dp[s]==0) return 0;
    
    bool ret = false;
    string tmp = "";
    
    for(int i = s;i<e;i++){
        tmp.push_back(A[i]);
        if(st.find(tmp)!=st.end()){
            if(str=="") ret |= solve(i+1,e,A,tmp);
            else ret |= solve(i+1,e,A,str + " " + tmp);
        }
    }
    dp[s] = ret;
    return ret;

}
    
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    int n = A.length();
    if(n==0) return {};
    
    res.clear();
    st.clear();
    dp.clear();
    dp.resize(n,-1);

    for(auto x:B) st.insert(x);
    
    
    solve(0,n,A,"");
            
    return res;
}
