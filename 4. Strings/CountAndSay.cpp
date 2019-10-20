/*
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.

LINK: https://www.interviewbit.com/problems/count-and-say/
*/
string Solution::countAndSay(int A) {
    string res = "1";
    A--;
    
    while(A--){
        int n = res.length();
        string tmp = "";
        int count = 1;
        
        for(int i = 1; i<n; i++){
            if(res[i]==res[i-1]) count++;
            else{
                tmp.push_back('0'+count);
                tmp.push_back(res[i-1]);
                count = 1;
            }
        }
        
        tmp.push_back('0'+count);
        tmp.push_back(res[n-1]);
        res = tmp;
    }
    
    return res;
}
