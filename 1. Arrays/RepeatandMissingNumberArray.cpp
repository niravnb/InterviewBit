/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

LINK: https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long int s1=0, s2=0;

    for(long long int i = 0; i<n;i++){
        long long int x = A[i];
        s1 += (i+1) - x;
        s2 += (i+1)*(i+1) - x*x;
    }
    int M,R;
    M = (s1 + (s2/s1))/2;
    R = M - s1;
    
    return {R, M};
}





/* 
Method 7 (Make two equations using sum and sum of squares)
Approach:

Let x be the missing and y be the repeating element.
Let N is the size of array.
Get the sum of all numbers using formula S = N(N+1)/2
Get product of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
Iterate through a loop from i=1….N
S -= A[i]
Sum_Sq -= (A[i]*A[i])
It will give two equations
x-y = S – (1)
x^2 – y^2 = Sum_sq
x+ y = (Sum_sq/S) – (2)

Time Complexity: O(n)
*/