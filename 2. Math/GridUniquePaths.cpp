/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

LINK: https://www.interviewbit.com/problems/grid-unique-paths/
*/


int Solution::uniquePaths(int A, int B) {
    int  i = 0;
    int j = 0;
    int count = 0;
    if(A==1 || B==1){
        return 1;
    }else{
    // while(i != A-1 || j != B-1){
    //     if(i+1<A){
    //     i++;
    //     count++;
    //     }
    //     if(j+1<B){
    //     j++;
    //     count++;
    //     }
    
    // vector<vector<int>> res(A, vector<int>(n));
    int dp[A][B];
    dp[A-1][B-1] = 0;
    for(int i = A-1; i>=0; i--){
        dp[i][B-1] = 1;
    }
    
    for(int j = B-1; j>=0; j--){
        dp[A-1][j] = 1;
    }
    
    for(int i = A-2; i>=0; i--){
        
        for(int j = B-2; j>=0; j--){
            
            dp[i][j] = dp[i][j+1] + dp[i+1][j];
        }
    }
    return dp[0][0];
    }
}


/*
Hint:
There is a mathematical approach to solving this problem.

Note that you have to take m + n - 2 steps in total. You have to take (m - 1) steps going down and (n-1) steps going right.

Let 0 denote a down step and 1 denote a right step.

So we need to find out the number of strings of length m + n - 2 which have exactly m - 1 zeroes and n - 1 ones.

Essentially we need to choose the positions of ‘1s’, and then ‘0s’ fall into the remaining positions.

So, the answer becomes Choose(m+n-2, n - 1).


int uniquePaths(int m, int n) {
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return (int)ans;
}


int calc(long long int n,long long int r)
{
    if(n==r)
        return 1;
    long long  ans = 1;
    for(long long int i=0;i<r;i++)
        ans = (ans * (n-i) / (i+1));
    return int(ans);
}
 
int Solution::uniquePaths(int A, int B)
{
    return calc(A+B-2,B-1);
}*/