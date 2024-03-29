/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/path-sum/
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
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int solve(TreeNode* A, int B, int sum){
     int l = 0, r = 0;
     
     if(!A) return 0;
     
     sum += A->val;
     if(sum==B && (!A->left && !A->right)) return 1;
     
     if(A->left){
         l = solve(A->left,B,sum);
         if(l==1) return 1;
     }
     if(A->right) r = solve(A->right,B,sum);
     
     return r;
 }
 
int Solution::hasPathSum(TreeNode* A, int B) {
    return solve(A,B,0);
}
