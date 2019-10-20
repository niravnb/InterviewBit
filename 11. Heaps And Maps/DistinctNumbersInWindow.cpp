/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

LINK: https://www.interviewbit.com/problems/distinct-numbers-in-window/
*/
vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B>A.size()) return {};
    
    vector<int> res(A.size()-B+1,1);
    
    unordered_map<int,int> m;
    
    for(int i = 0; i<B;i++){
        m[A[i]]++;
    }
    
    res[0] = m.size();
    
    for(int i = 1; i<A.size()-B+1; i++){
        m[A[i-1]]--;
        if(m[A[i-1]]==0) m.erase(A[i-1]);
        m[A[i+B-1]]++;

        res[i] = m.size();
    }
    
    return res;
}

