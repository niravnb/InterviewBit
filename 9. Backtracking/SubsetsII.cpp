/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

LINK: https://www.interviewbit.com/problems/subsets-ii/
*/
void findSubset(vector<int> &A, int i, vector<int> tmp, set<vector<int>> &s){
    
    for(;i<A.size();i++){
        vector<int> sb = tmp;
        sb.push_back(A[i]);
        s.insert(sb);
        findSubset(A, i+1, sb, s);

    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    int n = A.size();
    if(n==0) return {{}};
    
    sort(A.begin(),A.end());
    vector<vector<int> > res;
    vector<int>  tmp;
    set<vector<int>> s;
    s.insert(tmp);
    
    findSubset(A, 0, tmp, s);
    
    for(auto x:s){
        res.push_back(x);
    }
    return res;
}



/*
void helper(int index,vector<int> &A,vector<int> tempAns,vector<vector<int> > &ans)
{
    for(int i=index;i<A.size();i++)
    {
        tempAns.push_back(A[i]);
        ans.push_back(tempAns);
        helper(i+1,A,tempAns,ans);
        while(i<A.size()-1 && A[i] == A[i+1])
            i++;
        tempAns.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> tempAns;
    ans.push_back(tempAns);
    if(A.size() == 0)
        return ans;
    sort(A.begin(),A.end());
    helper(0,A,tempAns,ans);
    return ans;
}
*/