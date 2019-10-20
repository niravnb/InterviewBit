/*
Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.

LINK: https://www.interviewbit.com/problems/atoi/
*/

int Solution::atoi(const string A) {
    int i = 0 ,res = 0;;
    while(A[i]==' ') i++;
    int sign = 1;
    
    if(A[i]=='-') {
        sign = -1;
        i++;
    }
    if(A[i]=='+') i++;
    
    while(A[i]!='\0' && A[i]>='0' && A[i]<='9'){
        
        if(res>INT_MAX/10 || (res == INT_MAX/10 && A[i]-'0'>7)){
            if(sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        
        res = res*10 + A[i++]-'0';
    }
    
    return res*sign;
}
