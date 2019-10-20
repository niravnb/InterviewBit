/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

LINK: https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
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
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A) return NULL;
    
    if(!A->left && !A->right) return A;
    
    TreeNode* left = A->left;
    TreeNode* right = A->right;
    A->left=NULL;
    A->right=NULL;

    
    if(left){
        TreeNode* l = flatten(left);
        A->right = l;
    }
    if(right){
        TreeNode* r = flatten(right);
        TreeNode* tmp = A;
        while(tmp->right) tmp = tmp->right;
         tmp->right = r;
    }
    
    return A;
    
}
