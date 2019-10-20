/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

LINK: https://www.interviewbit.com/problems/max-product-subarray/
*/

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    if(n==0) return 0;
    
    int currMax, currMin, prevMax, prevMin, ans;
    
    ans = prevMax = prevMin = A[0];
    
    for(int i = 1;i<n;i++){
        currMax = max(A[i], max(A[i]*prevMax, A[i]*prevMin));
        currMin = min(A[i], min(A[i]*prevMax, A[i]*prevMin));
        
        ans = max(ans, currMax);
        
        prevMax = currMax;
        prevMin = currMin;
    }
    
    return ans;
}
