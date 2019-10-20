/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

LINK: https://www.interviewbit.com/problems/longest-valid-parentheses/
*/
int Solution::longestValidParentheses(string A) {
    int n = A.length(), res = 0;
    stack<int> s;
    s.push(-1);
    for(int i = 0; i<n;i++){
        if(A[i]=='(') s.push(i);
        else{
            s.pop();
            if(!s.empty()){
                res = max(res, i-s.top());
            }else s.push(i);
        }
    }    

    return res;
}
