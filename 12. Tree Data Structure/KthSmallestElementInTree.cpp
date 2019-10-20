/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 

LINK: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
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
 
 void solve(TreeNode* A, int B, vector<int> &res){
    
    if(!A) return;
    if(res.size()==B) return;
    
    solve(A->left,B,res);
    res.push_back(A->val);
    solve(A->right,B,res);
     
 }
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> res;
    solve(A,B,res);
    return res[B-1];
}
