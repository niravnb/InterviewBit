/*
Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

LINK: https://www.interviewbit.com/problems/divide-integers/
*/

int Solution::divide(int A, int B) {
    int sign = ((A<0)^(B<0))?-1:1;
    
    long long int tmp = 0, quotient = 0;
    long long int a = abs(1LL*A), b = abs(1LL*B);
    for(int i = 32;i>=0;i--){
        if(tmp + (b<<i)<=a){
            tmp += (b<<i);
            quotient |= (1LL<<i);
        }
    }
    
    if(quotient >= INT_MAX && sign == -1) return INT_MIN;
    if(quotient >= INT_MAX) return INT_MAX;
    
    return sign*quotient;
}
