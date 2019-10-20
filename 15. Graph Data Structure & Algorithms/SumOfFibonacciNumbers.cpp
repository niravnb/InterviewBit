/*
How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

LINK: https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/
*/

int Solution::fibsum(int A) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(1);
    int i = 2;
    while(1){
        int nextTerm = fib[i] + fib[i-1];
        
        if(nextTerm > A) break;
        
        fib.push_back(nextTerm);
        i++;
    }
    
    int count = 0;
    int ind = fib.size()-1;
    while(A){
        count += A/fib[ind];
        A = A%fib[ind];
        ind--;
    }
    return count;
}
