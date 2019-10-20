/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

LINK: https://www.interviewbit.com/problems/add-one-to-number/
*/

vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size(), carry = 1;
    vector<int> res;
    
    for(int i = n-1; i>=0;i--){
        int tmp = A[i]+carry;
        if(tmp>=10){
            carry = 1;
            res.push_back(tmp%10);
        }else{
            carry = 0;
            res.push_back(tmp);
        }
    }
    
    if(carry==1){
        res.push_back(1);
    }
    
    while(res.back()==0) res.pop_back();
    reverse(res.begin(),res.end());
    
    return res;
}

