/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.

LINK: https://www.interviewbit.com/problems/maximum-consecutive-gap/
*/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n==1) return 0;
    
    int mx = *max_element(A.begin(),A.end());
    int mn = *min_element(A.begin(),A.end());
    
    float delta = ((float)(mx-mn)/(float)(n-1));
    
    vector<int> MaxBucket(n-1,INT_MIN);
    vector<int> MinBucket(n-1,INT_MAX);
    
    for(int i =0; i<n; i++){
        if(A[i]==mn || A[i]==mx) continue;
        
        int ind = (A[i]-mn)/delta;

        MaxBucket[ind] = max(MaxBucket[ind],A[i]);
        MinBucket[ind] = min(MinBucket[ind], A[i]);
    }
    
    // for(int i =0; i< n-1 ; i++) cout << MaxBucket[i] << " ";
    // cout << endl;
    // for(int i =0; i< n-1 ; i++) cout << MinBucket[i] << " ";

    int res = 0, prevVal = mn;
    for(int i =0; i<n-1; i++){
        if(MinBucket[i]==INT_MAX) continue;
        res = max(res, MinBucket[i] - prevVal);
        prevVal = MaxBucket[i];
    }
    res = max(res, mx-prevVal);
    return res;
}
