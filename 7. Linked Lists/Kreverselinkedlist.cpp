/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

LINK: https://www.interviewbit.com/problems/k-reverse-linked-list/
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
 
 ListNode* reverse(ListNode* s, ListNode* e){
     ListNode* p = NULL, *c = s, *n;
     
     while(p!=e){
         n = c->next;
         c->next = p;
         p = c;
         c = n;
     }
     return p;
 }
 
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* p, *s, *e, *n, *tmp;
    if(B==1) return A;
    
    ListNode* head = new ListNode(0);
    head->next = A;
    p = head;
    s = A;
    
    while(s && s->next){
        int k = B;
        tmp = s;
        while(k--){
            e = tmp;
            tmp=tmp->next;
        }
        n = tmp;
        p->next = reverse(s,e);
        p = s;
        s = n;
    }
    
    return head->next;
    
}

