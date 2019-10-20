/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

LINK: https://www.interviewbit.com/problems/reorder-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reorderList(ListNode* A) {
    ListNode* s,*f,*m;
    s=  A;
    f=A;
    
    for(;f&&f->next;s=s->next, f=f->next->next);
    m = s;
    
    // reverse second half
    ListNode* p=NULL, *c = m->next, *n;
    while(c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    
    ListNode* h1 = A, *h2 = p, *nh1, *nh2;
    
    while(h1!=m && h2){
        nh1 = h1->next;
        nh2 = h2->next;
        h1->next = h2;
        h1 = h2;
        h1->next = nh1;
        h1 = nh1;
        h2 = nh2;
    }
    m->next = NULL;
    
    return A;
}
