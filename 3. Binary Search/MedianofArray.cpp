/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 

LINK: https://www.interviewbit.com/problems/median-of-array/
*/
double solve(const vector<int> &A, const vector<int> &B){
     int m = A.size(), n = B.size();
        
     int l = 0, r = m;
     while(l<=r){
         int pa = l + (r-l)/2;
         int pb = (m+n+1)/2 - pa;
         int maxlefta = (pa<=0)?INT_MIN:A[pa-1];
         int minrighta = (pa>m-1) ? INT_MAX:A[pa];
         int maxleftb = (pb<=0) ? INT_MIN:B[pb-1];
         int minrightb = (pb>n-1) ? INT_MAX:B[pb];
         
         if(maxlefta<=minrightb && maxleftb<=minrighta){
            
            if((m+n)%2==0){
                return (double)( max(maxlefta,maxleftb) + min(minrighta, minrightb) )/2;
            }else return (double)max(maxlefta,maxleftb);
            
         }else if(maxlefta>minrightb) r = pa-1;
         else l = pa+1;
         
     }
 
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int m = A.size(), n = B.size();
    
    if(m<n) return solve(A,B);
    else return solve(B,A);
    
}
