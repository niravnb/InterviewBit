/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

LINK: https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
*/
vector<int> Solution::lszero(vector<int> &A) {
    vector<int> res;
    int n = A.size();
    unordered_map<int,int> hash;
    
    int sum = 0, start = 0, len = 0;
    for(int i =0; i<n;i++){
        sum += A[i];
        
        if(sum==0){
            start = 0;
            len = i+1;
        }
        if(hash.find(sum)!=hash.end()){
            if(i-hash[sum]>len){
                start = hash[sum]+1;
                len = i - hash[sum];
            }
        }else hash[sum] = i;
    }
    
    while(len--) res.push_back(A[start++]);
    
    return res;
    
}
