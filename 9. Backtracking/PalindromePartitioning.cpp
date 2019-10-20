/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")

LINK: https://www.interviewbit.com/problems/palindrome-partitioning/
*/

vector<vector<string> > res;

bool isPalin(string s, int l, int r){
    
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void solve(string &A, int i, vector<string> tmp){
    if(i==A.length()){
        res.push_back(tmp);
        return;
    }
    for(int j=i; j<A.length();j++){
        if(isPalin(A,i,j)){
            tmp.push_back(A.substr(i,j-i+1));
            solve(A,j+1,tmp);
            tmp.pop_back();
        }
    }
    
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    res.clear();
    vector<string> tmp;
    solve(A,0,tmp);
    
    return res;
}
