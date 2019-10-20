/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

LINK: https://www.interviewbit.com/problems/combinations/
*/

// Editorial
// class Solution {
//     public:
//         void combineHelper(vector<int> &current, int n, int k, vector<vector<int> > &ans) {
//             if (k == 0) {
//                 vector<int> newEntry = current; 
//                 reverse(newEntry.begin(), newEntry.end());
//                 ans.push_back(newEntry);
//                 return;
//             }
//             if (n == 0 || n < k) return;
//             // We have 2 options here. We can either include n or not. 
//             // Option 1 : Do not include n.
//             combineHelper(current, n - 1, k, ans);
//             // Option 2 : Include n. 
//             current.push_back(n);
//             combineHelper(current, n - 1, k - 1, ans);
//             current.pop_back();
//             return;
//         }

//         vector<vector<int> > combine(int n, int k) {
//             vector<vector<int> > ans; 
//             vector<int> current;
//             combineHelper(current, n, k, ans);
//             sort(ans.begin(), ans.end());
//             return ans;
//         }
// };


// My code
void solve(vector<vector<int> > &res, vector<int> &curr, int n, int k, int i, int level){
    
    for(;i<=n && level<k;i++){
        curr.push_back(i);
        level++;
        if(level==k) res.push_back(curr);
        solve(res, curr, n, k, i+1, level);
        curr.pop_back();
        level--;
    }
    
    
}

vector<vector<int> > Solution::combine(int n, int k) {
    
    vector<vector<int> > res;
    vector<int> curr;
    solve(res, curr, n, k, 1, 0);
    
    return res;

}

// My other
// void myCombine(int n, int k, int d, int s, int e, vector<int> &data, vector<int> &arr,  vector<vector<int> > &res){
    
//     if(d==0) arr.clear();
//     if(d==k){
//         res.push_back(data);
//     }
//     else{
//     for(int i  = s; i<=e && e-i+1>= k-d && d<k;i++){
//         data[d]=arr[i];
//         myCombine(n, k, d+1, i+1, e, data, arr, res);
//     }}
// }

// vector<vector<int> > Solution::combine(int A, int B) {
    
//     if(B>A) return {};
//     int n = A;
//     vector<vector<int> > res;
//     vector<int> myarr, data(B,0);
//     for(int i = 1; i<=n;i++) myarr.push_back(i);
    
//     myCombine(A, B, 0, 0, n-1, data, myarr, res);
//     return res;
// }
