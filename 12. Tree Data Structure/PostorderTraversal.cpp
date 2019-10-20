/*
Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.

LINK: https://www.interviewbit.com/problems/postorder-traversal/
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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    vector<int> res;
    
    stack<TreeNode*> s;
    stack<int> o;
    // unordered_map<TreeNode*, int> m;
    TreeNode* temp = A;
    s.push(temp);
    // m[temp]=0;
    
    while(!s.empty()){
        temp = s.top();
        s.pop();
        
        o.push(temp->val);
        
        if(temp->left) s.push(temp->left);
        if(temp->right) s.push(temp->right);
        
    }
    
    while(!o.empty()){
        res.push_back(o.top());
        o.pop();
    }
    
    return res;
    
    // while(!s.empty()){
    //     temp = s.top();
        
    //     if(!temp->left) m[temp]++;
    //     if(!temp->right) m[temp]++;
        
        
    //     if(temp->left && m[temp]==0){
    //         m[temp]=1;
    //         temp = temp->left;
    //         s.push(temp);
    //         m[temp]=0;
    //     }
    //     else if(temp->right && m[temp]==1){
    //         m[temp]=2;
    //         temp = temp->right;
    //         s.push(temp);
    //         m[temp]=0;
    //     }else{
    //         s.pop();
    //         res.push_back(temp->val);
    //     }
        
    // }
    
    
    // return res;
    
    // vector<int> res;
    // TreeNode* curr = A, *t;
    // stack<TreeNode*> s;
    
    // // while(!s.empty() || curr){
    // //     if(curr){
    // //         s.push(curr);
    // //         curr = curr->left;
    // //     }else{
    // //         // t = s.top();
    // //         // curr = t->right;
    // //         if(!s.top()->right){
    // //             res.push_back(t->val);
    // //             s.pop();
    // //             curr = s.top();
    // //             }
    // //     }
    // // }
    
    // return res;
}
