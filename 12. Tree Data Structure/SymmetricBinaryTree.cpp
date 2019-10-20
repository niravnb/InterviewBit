/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/symmetric-binary-tree/
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
 
 bool isSym(TreeNode* l, TreeNode* r){
    if(!l && !r) return true;
    if(!l || !r) return false;
    
    if(l->val == r->val){
        return isSym(l->left, r->right) && isSym(l->right, r->left);
    }else return false;
 }
 
int Solution::isSymmetric(TreeNode* A) {
    if(!A) return true;
    if(!A->left && !A->right) return true;
    
    return isSym(A->left, A->right);
        
}
