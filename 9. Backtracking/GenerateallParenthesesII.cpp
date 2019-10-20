/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.

LINK: https://www.interviewbit.com/problems/generate-all-parentheses-ii/
*/

void myParens(int n, int open, int close, vector<string> &res, string s){
    
        if(n==0) return;
        
        if(close == n) res.push_back(s);
        else{
            if(open < n){
                myParens(n,open+1,close,res,s+'(');
            }
            if(open>close){
                myParens(n,open,close+1,res,s+')');
            }
            
        }
        
    }

vector<string> Solution::generateParenthesis(int A) {
        vector<string> res;
        
        myParens(A,0,0,res,"");
        
        return res;
}
