/*
Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.

LINK: https://www.interviewbit.com/problems/longest-common-prefix/
*/

string Solution::longestCommonPrefix(vector<string> &s)
{
    int n = s.size();
    int mnl = INT_MAX;
 
    for(int i=0;i<n;i++)
        mnl = min(mnl,int(s[i].length()));
 
    string res = "";
 
    for(int i=0;i<mnl;i++)
    {
        char temp = s[0][i];
        for(int j=1;j<n;j++)
        {
            if(temp != s[j][i])
                return res;
        }
        res.push_back(temp);
    }
    return res;
}

// string Solution::longestCommonPrefix(vector<string> &A) {
//     int n = A.size();
//     decltype(A.size()) i = 0;
//     int maxlen = INT_MAX;
//     for(;i<n;i++){
//         int lent = A[i].length();
//         maxlen = min(maxlen,lent);
//     }
//     string res;
//     char prev,cur;
//     int j = 0;
//     i=0;
//     if(maxlen == 0 || n == 0) return res;
//     if(n==1) return A[i];
    
    
    
//     for(i=1;i<n && j<maxlen;){
//         prev = A[i-1][j];
//         cur = A[i][j];
//         if(prev == cur){
//             i++;
//             if(i==n){
//                 res.push_back(prev);
//                 j++;
//                 i = 1;
//             }
//         }else{
//             j++;
//             i = 1;
//         }
        
//     }
    
//     return res;
// }
