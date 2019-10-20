/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

LINK: https://www.interviewbit.com/problems/max-continuous-series-of-1s/
*/
vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    int l = 0, r = 0, zeros = 0, maxlen = 0, s = 0;
    
    while(r<n){
        if(zeros<=B){
            if(A[r]==0) zeros++;
            r++;
        }
        if(zeros>B){
            if(A[l]==0) zeros--;
            l++;
        }
        if((r-l)>maxlen){
            maxlen = r-l;
            s = l;
        }
    }
    
    vector<int> res;
    for(int i = 0; i<maxlen; i++) res.push_back(i+s);
    
    return res;
    
}
//     // int maxLen = -1, ones = 0, zeros = 0;
//     // int st = 0, s = 0, e = 0, i = 0, len = 0, j=  0;
//     // vector<int> res;
    
//     // while(j<n){
//     //     while( j<n && A[j]==1) j++;
        
        
//     //     if(j<n && A[j]==0){
//     //         zeros++;
//     //         if(zeros>B){
//     //             // i++;
//     //             while(i<n && A[i]==1) i++;
//     //             zeros--;
//     //             i++;
//     //         }
//     //         // if(j<n-1) j++;
//     //         // if(maxLen < j-i+1){
//     //         //     maxLen = j-i+1;
//     //         //     e = j;
//     //         //     s = i;
//     //         // }
//     //         // j++;
//     //     }
        
//     //     if(j>i && j<n && maxLen < j-i+1){
//     //             maxLen = j-i+1;
//     //             e = j;
//     //             s = i;
//     //     }else if(j>=n && maxLen < j-i ){
//     //         maxLen = j-i;
//     //             e = j-1;
//     //             s = i;
//     //     }
            
//     //     j++;
        
//     // }
//     // if(maxLen == -1) maxLen = j;
    
//     // for(int i = s; i<=e; i++) res.push_back(i);
    
//     // return res;
    
//     // for(i = 0; i<n ; i++){
//     //     if(A[i]==1) ones++;
//     //     else{
//     //         zeros++;
//     //         if(zeros <= B){
//     //             ones++;
//     //         }else{
//     //             if(maxLen < i-st){
//     //                 maxLen = i-st;
//     //                 s = st;
//     //                 e = i-1;
//     //             }
//     //             if(B>0){
//     //                 ones = 1;
//     //                 zeros = 1;
//     //                 st = i;
//     //             }else{
//     //                 st = i+1;
//     //             }
                
//     //         }
//     //     }
//     // }
    
//     // if(maxLen < i-st){
//     //     maxLen = i-st;
//     //     s = st;
//     //     e = i-1;
//     // }
                
//     // for(int i = s; i<=e; i++) res.push_back(i);
    
//     // return res;
// }
