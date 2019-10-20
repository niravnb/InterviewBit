/*
Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4

LINK: https://www.interviewbit.com/problems/invert-the-binary-tree/
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
TreeNode* Solution::invertTree(TreeNode* A) {
        
        // TreeNode* root = A;
        // if(!root) return NULL;
        
        // root->left = invertTree(root->left);
        // root->right = invertTree(root->right);
        
        // TreeNode* tmp = root->left;
        // root->left = root->right;
        // root->right = tmp;
        
        // return root;
        
        if(!A) return NULL;
        TreeNode* l = A->left;
        TreeNode* r = A->right;
        
        
        A->right = invertTree(l);
        A->left = invertTree(r);
        
        return A;
}
