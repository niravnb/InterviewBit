/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3

LINK: https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
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
 
TreeNode* sortit(const vector<int> &A, int s, int e){
    TreeNode* tmp;
    if(s>e) return NULL;
    
    int mid = s + (e-s)/2;
    tmp = new TreeNode(A[mid]);
    tmp->left = sortit(A, s, mid-1);
    tmp->right = sortit(A, mid+1, e);

    return tmp;
} 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return sortit(A, 0, A.size()-1);
    
    
}
