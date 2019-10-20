/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations. 
Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' : 
aab
aba
baa
The answer might not fit in an integer, so return your answer % 1000003

 NOTE: 1000003 is a prime number
NOTE: Assume the number of characters in string < 1000003

LINK: https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/
*/

#define mod 1000003

long long int fact(vector<long long int> &facts, int n){
    if(facts[n]!=-1) return facts[n];
    
    long long int f = (n<=1)?1: (n%mod * fact(facts,n-1)%mod)%mod;
    facts[n] = f;
    return f;
}

// int modInverse(int a, int m){
//     a =a%m;
//     for(int i = 1; i<m; i++){
//         if((a*i)%m == 1) return i;
//     }
// }


long long int pw(long long int a, long long int b, long long int c){
    long long res = 1LL;
    while(b){
        res = (res*a)%c;
        b--;
        if(b%2==0){
            a = (a*a)%c;
            b = b/2;
        }
    }
    
    return res;
}
int Solution::findRank(string A) {
    int n = A.length();
    vector<long long int> facts(n+1,-1);
    long long int res = 1;
    
    for(int i = 0; i<n; i++){
        long long int lessthan = 0;
        
        for(int j = i+1; j<n; j++){
            if(A[i]>A[j]) lessthan++;
        }
        
        vector<int> arr(52,0);
        for(int j=i; j<n; j++){
            if(A[j]>='A' && A[j]<='Z'){
                arr[A[j]-'A']++;
            }else{
                arr[A[j]-'a'+26]++;
            }
            
        }
        
        
        long long int dfac = 1;
        for(int x:arr) dfac = (dfac*fact(facts,x)%mod)%mod;
        
        // long long int dfacInv = modInverse(int(dfac),1000003);
        
        // (1/A) % MOD = A ^ (MOD - 2) % MOD
        long long int dfacInv = pw(dfac,mod-2,mod);

        
        long long int tmp = (fact(facts,n-i-1)%mod * dfacInv%mod)%mod;
        res = (res  + (tmp*lessthan)%mod)%mod;
    }
    
    return res%mod;
}
