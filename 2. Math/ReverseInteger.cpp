/*
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

LINK: https://www.interviewbit.com/problems/reverse-integer/
*/

int Solution::reverse(int A) {
    int flag = false;
    if(A<0){
        flag = true;
        A = -1*A;
    }
    int res =0;
    
    while(A){
        if(res>=INT_MAX/10) return 0;
        res = res*10 + (A%10);
        A = A/10;
    }
    
    if(flag) return -1*res;
    return res;
}
