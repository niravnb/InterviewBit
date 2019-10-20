/*
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1

LINK: https://www.interviewbit.com/problems/power-of-2/
*/
string div2(string A){
    int n = A.length();
    int carry = 0, i = 0;
    string ret;
    
    while(i<n){
        int num = A[i]-'0';
        num += carry*10;
        carry = num%2;
        ret.push_back((num/2)+'0');
        i++;
    }
    
    // if(carry == 1) return "1";
    
    while(ret.length()>0  && ret[0]=='0') ret.erase(ret.begin());
    
    return ret;
}

int Solution::power(string A) {
    int n = A.length();
    
    if(n==1 && A[0]=='1') return 0;
    
    // if(n<63){
    //     int num = 2;
    //     cout << num & (num-1);
    //     return (num & (num-1)==0);
    // }
    
    while(A.length()>0){
        if(A.length()==1 && A[0]=='1') return 1;
        
        if((A[A.length()-1]-'0')%2 == 1) return 0;
        
        A = div2(A);
    }
    return 1;
}
