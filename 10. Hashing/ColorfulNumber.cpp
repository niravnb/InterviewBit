/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

LINK: https://www.interviewbit.com/problems/colorful-number/
*/

int Solution::colorful(int A) {
    int n = (to_string(A)).length();
    int l = 0;
    unordered_map<int,int> m;
    string s = to_string(A);
   
    for(int i =0; i<n; i++){
        int num = 1;
        for(int j = i; j<n; j++){
            num*=(s[j]-'0');
            m[num]++;
            if(m[num]>1) return 0;
        }
    }
    
     
    // for(int l = 1; l<=n; l++){
        
    //     for(int i = 0; i<=n-l; i++){
    //         string tmp =  s.substr(i,l);
    //         int num = 1;
    //         for(int j = 0; j<tmp.length(); j++){
    //             num *= (tmp[j]-'0');
    //         }
    //         m[num]++;
    //         if(m[num]>1) return 0;
    //     }
        
    // }
    
    
    return 1;
}
