/*
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          

LINK: https://www.interviewbit.com/problems/recover-binary-search-tree/
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
 void solve(TreeNode* A, TreeNode* &first, TreeNode* &last, TreeNode* &prev){
    if(!A) return;
    
    solve(A->left, first, last, prev);
    
    if(prev){
        if(prev->val>A->val){
            if(!first) first = prev;
            last = A;
        }
    }
    
    prev = A;
    solve(A->right, first, last, prev);
 }
 
vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode* first, *last, *prev;
    first = last = prev = NULL;
    
    solve(A, first, last, prev);
    
    return {last->val, first->val};
}
