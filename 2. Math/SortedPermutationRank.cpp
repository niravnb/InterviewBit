/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003

LINK: https://www.interviewbit.com/problems/sorted-permutation-rank/
*/

#define mod 1000003
#define MAX 256

long long int fact(vector<long long int> &facts, int n){
    if(facts[n]!=-1) return facts[n];
    
    long long int f = (n<=1)?1: (n%mod * fact(facts,n-1)%mod)%mod;
    facts[n] = f;
    return f;
}

void countSmaller(vector<int> &counts, string A){
    
    for(int i = 0; i<A.length(); i++) counts[A[i]]++;
    
    for(int i =1; i<MAX; i++) counts[i] += counts[i-1];
}

void updatecounts(vector<int> &counts, char a){
    for(int i = a; i<MAX; i++) counts[i]--;
}

int Solution::findRank(string A) {
    int len = A.length();
    vector<long long int> facts(len+1,-1);
    long long int mul;
    int rank = 1;
    
    vector<int> counts(MAX,0);

    countSmaller(counts, A);
    
    for(int i = 0; i<len; i++){
        // mul = mul/(len-i);
        mul = fact(facts, len-1-i);
        
        // int c = 0;
        // for(int j = i+1; j<len; j++){
        //     if(A[j]<A[i]) c++;
        // }
        
        // rank = (rank + (c*mul)%mod)%mod;
        
        int countsmallers = counts[A[i]-1];
        
        rank = (rank + (countsmallers*mul)%mod)%mod;
        
        updatecounts(counts, A[i]);
    }
    
    return rank%mod;
}
