/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
For example, 
given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 
We will retroactively disqualify such submissions and the submissions will incur penalties.

LINK: https://www.interviewbit.com/problems/multiply-strings/
*/
string Solution::multiply(string A, string B) {
    int na = A.length();
    int nb = B.length();
    
    int numa, numb, inda = 0, indb = 0;
    
    vector<int> res(na+nb,0);
    
    for(int i = na-1; i>=0; i--){
        
        numa = A[i]-'0';
        indb = 0;
        int carry = 0;
        for(int j = nb-1; j>=0; j--){
            numb = B[j]-'0';
            int sum = (numa*numb) + res[inda+indb] + carry;
            res[inda+indb] = sum%10;
            carry = sum/10;
            indb++;
        }
        if(carry>0) res[inda+indb] += carry;
        inda++;
    }
    
    // for(auto x:res) cout << x << " ";
    int i = na+nb-1;
    while(i>=0 && res[i]==0) i--;
    
    if(i==-1) return "0";
    
    string ret = "";
    while(i>=0) ret.push_back(res[i--]+ '0');
    
    return ret;
}
