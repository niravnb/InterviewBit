/*
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

LINK: https://www.interviewbit.com/problems/longest-substring-without-repeat/
*/

int Solution::lengthOfLongestSubstring(string A) {
    int n = A.size(), s = 0, e = 0, maxlen = 1;
    unordered_map<char,int> m;
    
    for(int i = 0;i<n;i++){
        
        if(m.find(A[i]) != m.end()){
            s = max(m[A[i]]+1,s);
        }
        m[A[i]] = i;
        e = i;
        maxlen = max(maxlen, e-s+1);
    }
    
    return maxlen;
}
