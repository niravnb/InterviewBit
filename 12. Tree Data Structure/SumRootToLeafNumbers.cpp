/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

LINK: https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
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
 #define MOD 1003
 void solve(TreeNode* A, int &ans, int currsum){
    if(!A) return;
    
    int tmp = ((currsum*10)%MOD + A->val)%MOD;
    if(!A->left && !A->right){
        ans = (ans + tmp)%MOD;
        return;
    }
    
    solve(A->left,ans,tmp);
    solve(A->right,ans,tmp);

 }
 
int Solution::sumNumbers(TreeNode* A) {
    int ans = 0;
    solve(A,ans,0);
    return ans;
    
}
