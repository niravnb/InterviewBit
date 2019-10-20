/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 

LINK: https://www.interviewbit.com/problems/n3-repeat-number/
*/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n1 = INT_MAX, n2 = INT_MAX;
    int c1 = 0, c2 = 0;
    
    for(int i =0; i<A.size();i++){
        if(A[i]==n1) c1++;
        else if(A[i]==n2) c2++;
        else if (c1==0){
            c1 = 1;
            n1 = A[i];
        }else if (c2==0){
            c2 = 1;
            n2 = A[i];
        }else{
            c1--;
            c2--;
        }
    }
    
    c1 = 0, c2 = 0;
    for(auto x:A){
        if(x==n1) c1++;
        else if(x==n2) c2++;
    }
    
    if(c1>A.size()/3) return n1;
    if(c2>A.size()/3) return n2;
    return -1;
    
}
