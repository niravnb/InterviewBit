/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20

LINK: https://www.interviewbit.com/problems/roman-to-integer/
*/
int getNum(char s){
    int nums[] = {1, 5, 10, 50, 100, 500, 1000};
    char romans[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    
    for(int i = 0; i<7; i++){
        if(romans[i]==s) return nums[i];
    }
    return -1;
}

int Solution::romanToInt(string A) {
    int n = A.length();
    int res = 0, p = 0;
    for(int i = n-1; i>=0; i--){
        int val = getNum(A[i]);
        if(val>=p){
            res += val;
        }else{
            res -= val;
        }
        p = val;
    }
    
    return res;
}
