/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example :

Given the below binary tree,

       1
      / \
     2   3
Return 6.

LINK: https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
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
 
 
 int getMax(TreeNode* r, int &res){
        if(!r) return 0;
        
        if(!r->left && !r->right){
            res = max(res,r->val);
            return r->val;  
        } 
        
        int lt = getMax(r->left,res);
        int rt = getMax(r->right,res);
        
        int maxsum = max(r->val, max(lt,rt)+r->val);
        
        res = max(res,max(maxsum,lt+rt+r->val));
        
        return maxsum;
 }
int Solution::maxPathSum(TreeNode* A) {
    
    int res = INT_MIN;
    
    getMax(A,res);
    
    return res;
    
}
