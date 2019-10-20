/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

LINK: https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void solve(TreeNode* A, int B, int sum,  vector<vector<int> > &res, vector<int> &tmp){
    if(!A) return;
    
    sum+= A->val;
    tmp.push_back(A->val);
    if(sum==B && (!A->left && !A->right)){
        res.push_back(tmp);
        tmp.pop_back();
        return;
    }
    
    if(A->left) solve(A->left, B, sum, res, tmp);
    if(A->right) solve(A->right, B, sum, res, tmp);
    tmp.pop_back();
 }
 
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > res;
    vector<int> tmp;
    
    if(!A) return res;
    
    solve(A, B, 0, res, tmp);
    
    return res;
}
