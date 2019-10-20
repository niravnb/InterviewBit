/*
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1

LINK: https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
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
 
 int maxInd(int s, int e, vector<int> &A){
     int mx = s;
     for(int i = s+1; i<=e; i++){
         if(A[i]>A[mx]) mx = i;
     }
     
     return mx;
 }

TreeNode* solve(int s, int e, vector<int> &A){
    if(s>e) return NULL;
    
    int i = maxInd(s,e,A);
    TreeNode* ret = new TreeNode(A[i]);
    ret->left = solve(s,i-1,A);
    ret->right = solve(i+1,e,A);
    
    return ret;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    if(n==0) return NULL;
    
    return solve(0,n-1,A);
}
