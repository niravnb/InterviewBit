/*
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

LINK: https://www.interviewbit.com/problems/add-binary-strings/
*/
string Solution::addBinary(string A, string B) {
    int n = A.length(), m = B.length(), i = 0 , j = 0;
    string res, myA, myB;
    
    if(m<n){
        for(int k = 0;k<n-m;k++) myB.push_back('0');
        myB.append(B);
        myA=  A;
    }
    else if(n<m){
        for(int k = 0;k<m-n;k++) myA.push_back('0');
        myA.append(A);
        myB = B;
    }else{
       myA=  A;
       myB = B;
    }
    

    int n1 = myA.length();
    int carry = 0;
        for(int k = n1-1; k>=0;k--){
            int s = (int)myA[k] + (int)myB[k] + carry - '0' - '0';
            if(s==3){
                res.push_back('1');
                carry = 1;
            }
            else if(s==2){
                res.push_back('0');
                carry = 1;
                
            }else if(s==1){
                res.push_back('1');
                carry = 0;
            }else{
                res.push_back('0');
                carry = 0;
            }
        }
        if(carry)  res.push_back('1');
    // }
    reverse(res.begin(),res.end());
    return res;
}
