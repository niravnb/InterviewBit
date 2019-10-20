/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.

LINK: https://www.interviewbit.com/problems/reverse-link-list-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void reverseit(ListNode* pp, ListNode* s, ListNode* e){
    // s->next = e;
    // s = s->next;
    // ListNode* p = e->next, *c = s->next, n;
    
    // s->next = e;
    // s->next->next = e->next;
    // p = e;
    
    ListNode* p = NULL, *c = s, *n;
    
    while(c!=e){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    s->next = e->next;
    e->next = s;
    // pp->next = e;
    
    
    
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
  ListNode* start = A, *end=A, *prev = A;
    
    if(B==C) return A;
    
    for(int i = 1; i<B-1;i++) prev = prev->next;
    for(int i = 1; i<B;i++) start = start->next;
    for(int i = 1; i<C;i++) end = end->next;
    
    
    // reverseit(prev,start,end);
    ListNode* pp = prev, *s = start, *e = end;
    ListNode* p = NULL, *c = s, *n;
    
    while(c!=e){ 
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    s->next = e->next;
    e->next = p;

    if(pp==s) A = e;
    else pp->next = e;

    
    return A;
}
