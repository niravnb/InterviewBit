/*
Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    } 
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.

LINK: https://www.interviewbit.com/problems/pretty-json/
*/
vector<string> Solution::prettyJSON(string A) {

    vector<string> res;
    string temp;
    int n = A.length();
    int i = 0, indent = 0, r = 0;

    while(A[i]!='\0'){
        while(A[i] == ' ') i++;
        
        if(A[i]=='[' || A[i]=='{'){
            temp.clear();
            for(int j = 0;j<indent;j++) temp.push_back('\t');
            temp.push_back(A[i]);
            res.push_back(temp);
            i++;
            indent++;
        }
        else if(A[i]==']' || A[i]=='}'){
            indent--;
            temp.clear();
            for(int j = 0;j<indent;j++) temp.push_back('\t');
            temp.push_back(A[i]);
            i++;
            if(i<n && A[i]==',') {
                temp.push_back(A[i]);
                i++;
            }
            res.push_back(temp);
        }
        else{
            int k = 0;
            while(i<n && A[i]!=','  && A[i] != '[' && A[i] != ']' && A[i] != '{' && A[i] != '}'){
                k++;
                i++;
            }
            temp.clear();
            for(int j = 0;j<indent;j++) temp.push_back('\t');
            // cout << A[i] << i << k << endl;

            if(A[i]==','){
                temp.append(A.substr(i-k,k+1));
                res.push_back(temp);
                i++;
            }else{
              temp.append(A.substr(i-k,k));
            //   cout << temp;
                res.push_back(temp);
            }
        }
        
        
        
        
        
    }
    
    // for(auto r:res)
    //     cout << r << endl;
    
    return res;
    
}
