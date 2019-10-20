/*
Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?

LINK: https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
*/

vector<int> Solution::getRow(int A) {
    vector<int> res;
    res.push_back(1);
    if(A==0) return res;
    
    for(int i = 0;i<A; i++){
        res.push_back(res[i]* (A-i)/(i+1));   // C(n,k+1) = C(n,k) * (n-k) / (k+1)
    }
    
    return res;
}
