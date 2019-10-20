/*
Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES
Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

LINK: https://www.interviewbit.com/problems/redundant-braces/
*/

int Solution::braces(string A) {
    stack<char> s;
    int corr=  0;
    
    for(int i = 0; i<A.length();i++){
        if(A[i]!=')') s.push(A[i]);
        else{
                corr=  0;
                while(!s.empty() && s.top()!='('){
                    if(s.top()=='+' || s.top()=='-' || s.top()=='/' || s.top()=='*'){
                        corr = 1;
                    }
                    s.pop();
                }
                if(corr==0) return 1;
                s.pop();
    }
    }
    
    return 0;
}
