// Build Identical Trees

/*
Given two binary trees T1 and T2, you have to find minimum number of insertions to be done in T1 to make it structurally identical to T2. Return -1 if not possible.

Notes

Assume insertions are done in a normal fashion in the BSTs.
Assume while inserting, if the value of a node v is equal to value being inserted, we insert it in left subtree of node v.
You can insert any positive or negative integer.
Example :

Input 1: 

T1:       10
         / \
        9   20

T2:       5
         / \
        2   7
       /
      1

If you insert 8 into T1, it will be structurally identical to T2. Hence answer is 1.


Input 2: 

T1:       10
         / \
        9   20

T2:       5
           \
            7

You cannot make T1 and T2 structurally identical. Hence answer is -1.
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
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    if(!A && !B) return 0;
    if(!B) return -1;
    if(!A) return 1 + cntMatrix(NULL, B->left) + cntMatrix(NULL, B->right);
    
    if(A && B){
        int l = cntMatrix(A->left, B->left);
        int r = cntMatrix(A->right, B->right);
        
        if(l==-1 || r==-1) return -1;
        
        return l+r;
    }
}

