/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

LINK: https://www.interviewbit.com/problems/least-common-ancestor/
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
 
 bool find(TreeNode* A, int val){
     
     if(!A) return false;
     
     if(A->val==val) return true;
     
     return find(A->left,val) || find(A->right,val);
 }
 
 
 int mylca(TreeNode* A, int B, int C){
        if(!A) return -1;
        if(A->val == B || A->val == C) return A->val;
        
        int l = mylca(A->left, B, C);
        int r = mylca(A->right, B, C);
        
        if(l!=-1 && r!=-1) return A->val;
        
        return (l!=-1)?l:r;
 }
 
int Solution::lca(TreeNode* A, int B, int C) {
    
    if(!A) return -1;
    
    bool val1 = find(A,B);
    bool val2 = find(A,C);
    
    if(val1&&val2){
        return mylca(A,B,C);
    }else return -1;
    
    
}
