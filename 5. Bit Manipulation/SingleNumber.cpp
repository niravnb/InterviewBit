/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3

LINK: https://www.interviewbit.com/problems/single-number/
*/

int Solution::singleNumber(const vector<int> &A) {
    int res = 0;
    for(int i = 0; i<A.size();i++){
        res ^= A[i];
    }
    return res;
}
