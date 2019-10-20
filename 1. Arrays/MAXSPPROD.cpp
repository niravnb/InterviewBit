/*
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9

LINK: https://www.interviewbit.com/problems/maxspprod/
*/

int Solution::maxSpecialProduct(vector<int> &A) {
    int L = 0, R = 0;
    long long int maxp = 0;
    int n = A.size();
    
    stack <int> LS, RS;
    long long int lp[n], rp[n];
    lp[0] = 0;
    rp[n-1] = 0;
    LS.push(0);
    RS.push(n-1);
    
    for(int i = 1; i< n-1; i++){
       
        //LS
        while(!LS.empty() && A[LS.top()] <= A[i]){
            LS.pop();
        }
        
        if(LS.empty()){
            L = 0;
        }else{
            L = LS.top();
            
        }
        lp[i] = L;
        LS.push(i);
        
    }
    
    for(int i = n-2; i>=0; i--){
        while(!RS.empty() && A[RS.top()] <= A[i]){
            RS.pop();
        }
        
        if(RS.empty()){
            R = 0;
        }else{
            R = RS.top();
        }
        rp[i]=R;
        RS.push(i);
    }
    
    for(int i = 1; i<n-1; i++){
        maxp = max(maxp,(((long long int)lp[i]*(long long int)rp[i])));
    }

    return maxp%1000000007;
}


/* 
Hint:

Ok, lets try to calculate LeftSpecialValue.

Lets make a stack A.
We will keep elements in strictly decreasing order in stack A.

When processing the ith element remove all the elements from the stack which have value less than or equal to ith element.
Now whatever element will remain at the top of index will give the index corresponding to LeftSpecialValue. If no element is at top then take it as 0.

Push ith element in stack A now.

You can see each element is pushed and popped for atmax one time. Hence the solution runs in O(n) time.

Do the similar thing for RightSpecialValue.

*/
