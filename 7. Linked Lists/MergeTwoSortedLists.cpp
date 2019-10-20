/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

LINK: https://www.interviewbit.com/problems/merge-two-sorted-lists/
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
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* ret, *h;
    if(A->val <= B->val){
        ret = A;
        A = A->next;
    }
    else{
        ret = B;
        B = B->next;
    }
    h = ret;
    while(A && B){
        if(A->val <= B->val){
            ret->next = A;
            A = A->next;
        }else{
            ret->next = B;
            B = B->next;
        }
        ret = ret->next;
    }
    
    while(A){
       ret->next = A;
        A = A->next; 
        ret = ret->next;
    }
    
    while(B){
       ret->next = B;
        B = B->next; 
        ret = ret->next;
    }
    
    return h;
}
