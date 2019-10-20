/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

LINK: https://www.interviewbit.com/problems/evaluate-expression/
*/

int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    int n = A.size(), a, b;
    for(int i = 0; i<n; i++){
        while(i<n && A[i]!="*" && A[i]!="+" && A[i]!="-" && A[i]!="/"){
            s.push(stoi(A[i]));
            i++;
        }
        
        b = s.top();
        s.pop();
        if(!s.empty()){
            a = s.top();
            s.pop();
        } else return b;
        
            
        if(A[i]=="+"){
            s.push(a+b);
        }else if(A[i]=="-"){
            s.push(a-b);
        }else if(A[i]=="*"){
            s.push(a*b);
        }else if(A[i]=="/"){
            s.push((int)(a/b));
        }
    }
    
    return s.top();
}
