/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

LINK: https://www.interviewbit.com/problems/search-for-a-range/
*/
int BS(const vector<int> &A, int B, bool flag){
    int l = 0, r = A.size()-1, res = -1,m;
    while(l<=r){
        m = l + (r-l)/2;
        if(A[m]==B){
            res = m;
            if(flag) r = m-1;
            else l = m+1;
            
        }else if(A[m]>B) r = m-1;
        else l = m+1;
    }
    
    return res;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return {BS(A,B,true), BS(A,B,false)};
}
