/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False

LINK: https://www.interviewbit.com/problems/palindrome-integer/
*/

int Solution::isPalindrome(int A) {
    if(A<0) return false;
    int temp = A, A1 = 0;
    while(A!=0){
        A1 = A1*10 + A%10;
        A/= 10;
    }
    
    if(A1 == temp){
        return true;
    }
    return false;
    
    
    // string res = to_string(A);
    // int j = res.size()-1;
    // for(int i = 0; i <= j; i++, j--){
    //     if(res[i] != res[j]) return false;
    // }
    // return true;
    
}
