/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

LINK: https://www.interviewbit.com/problems/letter-phone/
*/
string phone[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> res;

void solve(string A, int i, string tmp){
    
    if(i==A.length()){
        res.push_back(tmp);
        return;
    }
    
    int num = A[i]-'0';
    int len = phone[num].length();
    // cout << num << " " << len << endl; 
    for(int j=0; j<len; j++){
        tmp.push_back(phone[num][j]);
        solve(A,i+1,tmp);
        tmp.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    int n = A.length();
    if(n==0) return {};
    res.clear();
    solve(A,0,"");
    
    return res;
}
