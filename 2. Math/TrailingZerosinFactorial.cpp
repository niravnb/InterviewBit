/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1

LINK: https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
*/

int Solution::trailingZeroes(int A) {
    int n = 5, res = 0;
    while(n<=A){
        res += A/n;
        n *= 5;
    }
    return res;
}
