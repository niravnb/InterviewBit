/*
Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?

Example :

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

LINK: https://www.interviewbit.com/problems/unique-binary-search-trees-ii/
*/

int Solution::numTrees(int A) {
    
    vector<int> dp(A+2,0);
    dp[0] = 1, dp[1] = 1;
    
    for(int i = 2;i<=A;i++){
        for(int j = 0; j<i;j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[A];
}
