/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

LINK: https://www.interviewbit.com/problems/power-of-two-integers/
*/

int Solution::isPower(int A) {
    int prod = 1;
    bool res = false;
    int t = A;
    if(A<2){ 
        return true;
        
    }
    for(int i = 2; i*i<=A; i++){
        if(A%i == 0){
            prod = i;
            for(int j = 1; j<32; j++){
                prod *=  i;
                if(prod == A){
                    return true;
                }
            }
        
        }
    }
    
    return res;
}
