/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.

LINK: https://www.interviewbit.com/problems/diffk-ii/
*/

int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, bool> m;
    for(int i = 0; i< n; i++){
        if(m.find(A[i]-B)!=m.end() || m.find(A[i]+B)!=m.end()) return 1;
        
        m[A[i]] = true;
    }
    return 0;
}
