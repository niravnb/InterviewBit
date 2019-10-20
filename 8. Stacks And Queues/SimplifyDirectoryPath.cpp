/*
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.

LINK: https://www.interviewbit.com/problems/simplify-directory-path/
*/

string Solution::simplifyPath(string A) {
    int n = A.length();
    string res = "";
    stack<string> s;
    
    for(int i =0; i<n;i++){
        string tmp = "";
        while(i<n && A[i]=='/') i++;
        
        while(i<n && A[i]!='/') tmp += A[i++];
        
        if(tmp==".."){
            if(!s.empty()) s.pop();
        }else if(tmp == ".") continue;
        else{
            s.push(tmp);
        }
    }
    
    while(!s.empty()){
        string tmp = s.top();
        s.pop();
        
        if(res=="") res = tmp;
        else res = tmp + "/" + res;
    }
    
    res = "/" + res;
    return res;
    
}
