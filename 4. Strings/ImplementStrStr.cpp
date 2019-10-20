/*
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 

LINK: https://www.interviewbit.com/problems/implement-strstr/
*/
void computelps(vector<int> &lps, string B){
    int n = B.length();
    int len = 0;
    int i;
    lps[0] = 0;
    
    for(i=1;i<n;){
        if(B[i]==B[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
        
    }
}

int Solution::strStr(const string A, const string B) {
    
    if(A=="" && B== "") return -1;
    if(B=="") return -1;
    
    int n = A.length(), m = B.length();
    
    // KMP
    vector<int> lps(m,-1);
    
    computelps(lps,B);
    
    int i = 0, j = 0;
    
    while(i<n){
        while(A[i]==B[j] && i<n && j<m){
            i++;
            j++;
        }
        
        if(j==m){
            return i-m;
        }
        
        if(i<n && A[i]!=B[j]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    
    return -1;
}



// Robin Karp
    // long long int d = 256, p =103, i , j;
    // long long int h = 1;
        
    // for( i = 0; i < m-1; i++){
    //   h = (d*h)%p;   
    // }
    
    
    // int ah = 0, bh = 0;
    
    // for( i = 0; i < m; i++){
    //     ah = (ah*d + A[i])%p;
    //     bh = (bh*d + B[i])%p;

    // }
    
    
    // for(i = 0; i<=(n-m);i++){
    //     if(ah==bh){
    //         for(j = 0; j<m;j++){
    //             if(A[i+j]!=B[j]) break;
    //         }
    //         if(j==m) return i;
    //     }
    //     if(i<n-m){
    //         ah = (d*(ah - A[i]*h) + A[i+m])%p;
    //         if(ah < 0) ah = (ah + p);
    //     }
        
    // }