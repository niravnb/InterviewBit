/*
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

LINK: https://www.interviewbit.com/problems/2sum-binary-tree/
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
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> s1, s2;
    TreeNode* tmp1 = A;
    TreeNode* tmp2 = A;
    
    while(!s1.empty() || !s2.empty() || tmp1 || tmp2){
        if(tmp1 || tmp2){
            if(tmp1){
                s1.push(tmp1);
                tmp1 = tmp1->left;
            }
            if(tmp2){
                s2.push(tmp2);
                tmp2 = tmp2->right;
            }
        }else{
            if(s1.top() == s2.top()) return 0;
            
            int val1 = s1.top()->val;
            int val2 = s2.top()->val;
            
            if(val1+val2 == B) return 1;
            
            if(val1+val2 > B){
                tmp2 = s2.top()->left;
                s2.pop();
            }else{
                tmp1 = s1.top()->right;
                s1.pop();
            }
        }
    }
    
    return 0;
    
}

