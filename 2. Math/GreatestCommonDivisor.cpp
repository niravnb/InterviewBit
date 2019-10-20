/*
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 

LINK: https://www.interviewbit.com/problems/greatest-common-divisor/
*/

int Solution::gcd(int A, int B) {
    // if(A==0 || B ==0){
    //     return A!=0?A:B;
    // }
    // int n = min(A,B);
    // int gcd;
    // for(int i = 1; i <=n; i++){
    //     if(A%i == 0 && B%i ==0) gcd = i;
    // }
    
    // return gcd;
    
    return B==0?A:gcd(B, A%B);
}
