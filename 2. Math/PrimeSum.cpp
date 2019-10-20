/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

LINK: https://www.interviewbit.com/problems/prime-sum/
*/

vector<int> Solution::primesum(int A) {
    vector<bool> primes(A+1,1);
    primes[0] = primes[1] = 0;
    for(int i = 2; i*i<=A; i++){
        if(primes[i]==1){
            for(int j = i*i; j<=A; j = j+i) primes[j] = 0;
        }    
    }
    
    for(int i = 0; i<=A; i++){
        if(primes[i]==1 && primes[A-i]==1) return {i,A-i};
    }
}
