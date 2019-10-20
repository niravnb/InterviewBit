/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

LINK: https://www.interviewbit.com/problems/length-of-last-word/
*/

int Solution::lengthOfLastWord(const string A) {
    int res =0, n=A.length(), i=n-1;
    
    while(A[i]==' ') i--;
    
    for(;i>=0 && A[i]!=' ';i--,res++);
    
    // if(i==0 && A[i]!=' ') return 0;
    
    return res;
    
}
