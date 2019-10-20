/*Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode *c = A, *p = NULL, *n;
    
    while(c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    
    return p;
}
