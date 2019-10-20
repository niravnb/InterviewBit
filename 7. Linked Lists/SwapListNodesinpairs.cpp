/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

LINK: https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* Solution::swapPairs(ListNode* A) {
    if(!A || !A->next) return A;

    // Recursive
    ListNode* f = A, *s = A->next;

    f->next = swapPairs(s->next);
    s->next = f;
    
    return s;
    
    // Iterative
    // ListNode* c =A, *n = A->next, *p = NULL, *nn, *ret = n;
    
    // while(c && n){
    //     nn = n->next;
    //     n->next = c;
    //     if(p) p->next = n;
    //     c->next = nn;
        
    //     p = c;
    //     c = nn;
    //     if(nn) n = c->next;
    //     else n = NULL;
    // }
    
    // return ret;
}

