/*
Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

LINK: https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
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
 int findInd(vector<int> &inorder, int x, int s, int e){
     for(int i =s; i<=e;i++){
         if(inorder[i]==x) return i;
     }
     return -1;
 }
 
TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int pS, int pE, int s, int e, unordered_map<int, int> &map){
    if(s>e) return NULL;
    
    if(s==e) return new TreeNode(postorder[pE]);
    
    TreeNode* node = new TreeNode(postorder[pE]);
    
    int i = map[postorder[pE]];
    int len = i-s;
    node->left = solve(inorder, postorder, pS, pS+len-1,s,i-1,map);

    node->right = solve(inorder, postorder, pS+len, pE-1,i+1,e,map);
    
    
    return node;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size(), m = B.size();
    if(n==0 || m==0 || n!=m) return NULL;
    
    unordered_map<int, int> map;
    
    for (int i = 0; i <A.size(); i++) {
        map.insert(make_pair(A[i], i));
    }
    
    return solve(A,B,0,m-1,0,n-1, map);
}
