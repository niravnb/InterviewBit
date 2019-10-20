/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.
Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 Note 1: that using recursion has memory overhead and does not qualify for constant space.
Note 2: The tree need not be a perfect binary tree.

LINK: https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
TreeLinkNode* getNext(TreeLinkNode* root)
{
    TreeLinkNode* temp = root->next;
    while(temp)
    {
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp = temp->next;
    }
    return NULL;
}
 
void Solution::connect(TreeLinkNode* A)
{
    if(A==NULL)
        return;
 
    A->next = NULL;
 
    while(A)
    {
        TreeLinkNode* temp = A;
        while(temp)
        {
            if(temp->left)
            {
                if(temp->right)
                    temp->left->next = temp->right;
                else
                    temp->left->next = getNext(temp);
            }
            if(temp->right)
                temp->right->next = getNext(temp);
 
            temp = temp->next;
        }
        if(A->left)
            A = A->left;
        else
        if(A->right)
            A = A->right;
        else
            A = getNext(A);
    }
}



/*

 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 
 void myConnect(TreeLinkNode* r, TreeLinkNode* n){
        
        if(!r) return;
        
        r->next = n;
        TreeLinkNode* lt = r->left;
        TreeLinkNode* rt = r->right;
        
        if(lt) myConnect(lt,rt);
        if(rt) myConnect(rt,n?n->left:NULL);
        
}

void dfs(TreeLinkNode *root){
        if (!root){return;}  // if current node is not valid return
         
        if (root->next==NULL){ // if current node is not in the right boundary of this level
            if (root->right){root->right->next = NULL;} // if has right child, its next is null
            if (root->left){root->left->next = root->right;}//if has left child, its next is its right
        }else{ // if the current node has next node in its right
            TreeLinkNode* p = root->next; //the pointer travle along this level 
            TreeLinkNode* q=NULL; // the next valid pointer in the level+1 , or NULL if not found
            while (p){ //find the next valid child of root node
                if (p->left){q =p->left; break;}
                if (p->right){q =p->right; break;}
                p=p->next;
            }
            if (root->right){root->right->next = q;} //set right child if exists
            if (root->left && root->right ){root->left->next = root->right;}//set left if right exists
            if (root->left && !root->right) {root->left->next = q;} // set left if right not exist
        }
         
        dfs(root->right); // search right child, order is important
        dfs(root->left);  // search left child
    }
 
 
    
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* root = A;
    root->next = NULL;
    dfs(root);
    
    // myConnect(A,NULL);
    
  
}

*/