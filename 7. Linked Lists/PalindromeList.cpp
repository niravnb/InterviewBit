/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

LINK: https://www.interviewbit.com/problems/palindrome-list/
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
 
//  int isPalin(ListNode* &l, ListNode* r){
//     if(!r) return 1;
    
//     if(isPalin(l,r->next)){
//         if(l->val == r->val){
//             l = l->next;
//             return 1;
//         }
//     } 
    
//     return 0;
    
//  }
 

 int isPalin(ListNode* &l, ListNode* r){
    if(!r) return 1;
    
    int tmp = isPalin(l,r->next);
    
    if(tmp==0) return 0;
    
    if(l->val == r->val){
        l = l->next;
        return 1;
    }else return 0;
    
 }
 
int Solution::lPalin(ListNode* A) {
    
    return isPalin(A,A);
}

