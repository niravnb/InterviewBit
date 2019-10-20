/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
There might be multiple gray code sequences possible for a given n.
Return any such sequence.

LINK: https://www.interviewbit.com/problems/gray-code/
*/

void myGrayCode(vector<int> &res, int n, int &num){
    
    if(n==0){
        res.push_back(num);
        return;
    }
    
    myGrayCode(res, n-1, num);
    
    num = num^(1<<(n-1));
    myGrayCode(res, n-1, num);


    
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // vector<int> res;
    // int num = 0;
    // myGrayCode(res, A, num);
    
    // return res;
    
    vector<int>res;
    for(int i=0;i<(1<<A);i++){
        res.push_back(i^(i>>1));
    }
    return res;
    
}
