/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = [3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem

LINK: https://www.interviewbit.com/problems/jump-game-array/
*/

int Solution::canJump(vector<int> &A) {
    
    int toReach = A.size()-1;
    int maxPossibleJump = A[0];
    
    for(int i=0; i<=maxPossibleJump;i++){
        if(i+A[i]>= toReach) return true;
        maxPossibleJump = max(maxPossibleJump,i+A[i]);
    }
    
    return false;
}
