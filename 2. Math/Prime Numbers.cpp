/*Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.
*/

vector<int> Solution::sieve(int A) {
    vector<bool> isprime(A+1,true);
    isprime[0]=false;
    isprime[1] = false;
    for(int i =2; i*i<=A; i++){
        if(isprime[i]){
            for(int j = 2*i; j<=A; j=j+i){
                isprime[j] = false;
            }
        }
    }
    
    vector<int> res;
    for(int i =2; i<=A;i++){
        if(isprime[i]){
            res.push_back(i);
        }
    }
    
    return res;
}
