/*
Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

LINK: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
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

 
 
TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int pS, int pE, int s, int e, unordered_map<int, int> &map){
    if(s>e) return NULL;
    
    TreeNode* node = new TreeNode(preorder[pS]);

    if(s==e) return node;
    
    int i = map[preorder[pS]];
    int len = i-s;
    node->left = solve(inorder, preorder, pS+1, pS+len,s,i-1,map);

    node->right = solve(inorder, preorder, pS+len+1, pE,i+1,e,map);
    
    
    return node;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size(), m = B.size();
    if(n==0 || m==0 || n!=m) return NULL;
    
    unordered_map<int, int> map;
    
    for (int i = 0; i <B.size(); i++) {
        map.insert(make_pair(B[i], i));
    }
    
    return solve(B,A,0,m-1,0,n-1, map);
}