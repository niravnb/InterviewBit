/*
Given a 3Xn board, find the number of ways to color it using at most 4 colors such that no two adjacent boxes have same color. Diagonal neighbors are not treated as adjacent boxes. 
Output the ways%1000000007 as the answer grows quickly.

1<= n < 100000

Example:
Input: n = 1
Output: 36

LINK: https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
*/

#define MOD 1000000007
int Solution::solve(int A) {
    
    long int c3 = 24, c2 = 12;
    for(int i = 2; i<=A; i++){
        long int t = c3;
        c3 = ((11*c3)%MOD + (10*c2)%MOD)%MOD;
        c2 = ((5*t)%MOD + (7*c2)%MOD)%MOD;
    }
    return (c3+c2)%MOD;
    
}
