/*Implement pow(A, B) % C.

In other words, given A, B and C,
find (AB)%C.

Input : A = 2, B = 3, C = 3
Return : 2 
2^3 % 3 = 8 % 3 = 2
*/

int myMod(int A, int B, int C){
    if(A==0) return 0;
    if(B==0) return 1;
    long long int res;
    res = myMod(A,B/2,C);
    res = (res*res)%C;
    
    if(B%2) res = (res*A)%C;
    
    return (int)(res+C)%C;
}

int Solution::Mod(int A, int B, int C) {
    
    return myMod(A,B,C);
}
