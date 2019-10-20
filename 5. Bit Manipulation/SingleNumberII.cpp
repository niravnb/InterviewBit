/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4

LINK: https://www.interviewbit.com/problems/single-number-ii/
*/

int Solution::singleNumber(const vector<int> &A) {
    int n = A.size(), res = 0, x;
    
    for(int i = 0;i<32;i++){
        x = (1<<i);
        int count = 0;
        for(int j=0;j<n;j++){
            if(A[j]&x) count++;
        }
        if(count%3==1) res += x;
    }
    
    return res;
}
