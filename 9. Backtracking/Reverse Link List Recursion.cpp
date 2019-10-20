/*Reverse a linked list using recursion.

Example :
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* myrev(ListNode* p, ListNode* c){
     
    if(!c) return p;

    ListNode*n = c->next;
    c->next = p;
    
    return myrev(c,n);
 }
 
ListNode* Solution::reverseList(ListNode* A) {
    
    return myrev(NULL,A);
}


// Reverses the linkedList which starts from head
// Returns the end node which is the head of the reversed list.  
// ListNode *reverseList(ListNode *p) {
//     if (p->next == NULL || p == NULL) {
//         return p;
//     }
//     ListNode *nextNode = p->next;
//     ListNode *head = reverseList(p->next);
//     nextNode->next = p;
//     p->next = NULL;

//     return head;
// }