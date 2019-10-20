/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

LINK: https://www.interviewbit.com/problems/subset/
*/

void findSubsets(vector<int> &A, int s, int e, vector<vector<int> > &res, vector<int> tmp){
    
    res.push_back(tmp);
    if(s>e) return;
    
    for(int i = s; i<=e ; i++){
        tmp.push_back(A[i]);
        findSubsets(A,i+1,e,res,tmp);
        tmp.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    int n = A.size();
    if(n==0) return {{}};
    sort(A.begin(),A.end());
    
    vector<vector<int> > res;
    vector<int> tmp = {};
    findSubsets(A,0,n-1,res, tmp);
    return res;
}
