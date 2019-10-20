/*
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2

LINK: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
*/

bool isPali(string s){
    for(int i =0, j = s.length()-1;i<=j;i++,j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}

int Solution::solve(string A) {
    int res = 0;
    while(A.length()>0){
        if(isPali(A)) return res;
        else{
            res++;
            A.erase(A.end()-1);
        }
    }
    return res;
}
