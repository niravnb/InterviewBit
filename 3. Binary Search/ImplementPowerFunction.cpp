/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

LINK: https://www.interviewbit.com/problems/implement-power-function/
*/

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // find (x^n % d)
    if(x==0 && n==0) return 0;
    if(n==0) return 1;
    if(n==1){
        return (x+d)%d;
    }
    
    long long temp;
    temp = pow(x,n/2,d);
    temp = (temp*temp)%d;
    if(n%2!=0) temp = (temp*x)%d;
    
    return (temp+d)%d;

}
