/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
     return minimum time to paint all boards % 10000003
Example

Input : 
  K : 2
  T : 5
  L : [1, 10]
Output : 50

LINK: https://www.interviewbit.com/problems/painters-partition-problem/
*/
#define mod 10000003

int numOfPainters(vector<int> &C, long long int maxLen){
    int n = C.size();
    long long int sum = 0;
    int numPainters = 1;
    
    for(int i = 0; i<n; i++){
        sum += C[i];
        if(sum > maxLen){
            numPainters++;
            sum = C[i];
        }
    }
    return numPainters;
}


int Solution::paint(int K, int T, vector<int> &C) {
    long long int n = C.size();
    long long int low = *max_element(C.begin(),C.end());
    long long int high = accumulate(C.begin(),C.end(),0);
    
    while(low<high){
        long long int mid = low + (high-low)/2;
        int requiredPainters = numOfPainters(C,mid);
        
        if(requiredPainters<=K) high = mid;
        else low = mid+1;
    }
    return (low*T)%mod;
}

