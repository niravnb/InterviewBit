/*
Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.

LINK: https://www.interviewbit.com/problems/inorder-traversal/
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
 
 // Better
vector<int> Solution::inorderTraversal(TreeNode* A)
{
    vector<int> res;
    stack<TreeNode*> st;
 
    TreeNode* curr = A;
 
    while(!st.empty() || curr)
    {
        while(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
 
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}


//  My code
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> res;
    
    stack<TreeNode*> s;
    TreeNode* temp = A;
    s.push(A);
    while(temp->left){
        temp = temp->left;
        s.push(temp);
    }
    
    while(!s.empty()){
        temp = s.top();
        s.pop();
        res.push_back(temp->val);
        if(temp->right){
            s.push(temp->right);
            temp = temp->right;
            while(temp->left){
                temp = temp->left;
                s.push(temp);
            }
        }
    }
    
    
    return res;
}
