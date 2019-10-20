/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

LINK: https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    if(!A) return {};
    vector<vector<int> > res;
    queue<TreeNode*> q;
    q.push(A);
    bool flag=  true;
    
    while(!q.empty()){
        int n = q.size();
        vector<int> tmp(n);
        for(int i =0;i<n;i++){
            TreeNode* cur = q.front();
            q.pop();
            int ind = flag?i:n-i-1;
            tmp[ind] = cur->val;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        res.push_back(tmp);
        flag = !flag;
    }
    
    return res;
    
}
