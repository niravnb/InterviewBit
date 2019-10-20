/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

LINK: https://www.interviewbit.com/problems/combination-sum-ii/
*/


void solve(vector<int> &A, int B, set<vector<int>> &res, vector<int> tmp, int i, int currSum){
    
    if(currSum == B){
        res.insert(tmp);
        return;
    }
    
    if(i>=A.size()) return;
    if(currSum+A[i]>B){
        return;
        // solve(A, B, res, tmp, i+1, currSum);
    }else{
        tmp.push_back(A[i]);
        solve(A, B, res, tmp, i+1, currSum+A[i]);
        tmp.pop_back();
        solve(A, B, res, tmp, i+1, currSum);

    }
       
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n = A.size();
    if(n==0){
        if(B == 0) return {{}};
        else return {};
    }
    sort(A.begin(),A.end());
    set<vector<int> > res;
    vector<int> tmp;
    solve(A, B, res, tmp, 0, 0);
        
    vector<vector<int> > ret;
    for(auto x:res) ret.push_back(x);
        
    return ret;
}


// set<vector<int> > comb;
 
// void backtrack(vector<int> &A, int i, int sum, int B, vector<int> &temp)
// {
//     if(sum>=B)
//         return;
//     for(;i<A.size();i++)
//     {
//         temp.push_back(A[i]);
//         sum += A[i];
//         if(sum == B)
//             comb.insert(temp);
//         backtrack(A, i+1, sum, B, temp);
//         temp.pop_back();
//         sum -= A[i];
//     }
// }
 
// vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
// {
//     sort(A.begin(), A.end());
//     comb.clear();
//     vector<int> temp;
 
//     backtrack(A, 0, 0, B, temp);
 
//     vector<vector<int> > res;
//     set<vector<int> >::iterator it = comb.begin();
 
//     for(;it!=comb.end();it++)
//         res.push_back(*it);
 
//     return res;
// }