/*
Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.

LINK: https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
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
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            if(a.first == b.first) return a.second<b.second;
            return a.first<b.first;
        }
    };
    
    
    void solve(TreeNode* root, map<int, vector<pair<int,int>>> &mp, int level, int depth){
        
        if(!root) return;
        
        mp[level].push_back({depth,root->val});
        solve(root->left,mp,level-1, depth+1);
        solve(root->right,mp,level+1, depth+1);
        
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<pair<int,int>>> mp;
        solve(root, mp, 0,0);
        
        vector<vector<int>> res;
        for (auto it:mp){
            
            auto tmp = it.second;
            sort(tmp.begin(), tmp.end(), cmp());
            
            vector<int> tmp2;
            for(auto x: tmp) tmp2.push_back(x.second);
            
            res.push_back(tmp2);
        }
        
        return res;
        
        
    }
};