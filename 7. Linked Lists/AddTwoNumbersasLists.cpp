/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

LINK: https://www.interviewbit.com/problems/add-two-numbers-as-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(!A) return B;
    if(!B) return A;
    
    ListNode* head = new ListNode(0);
    ListNode* ret = head;
    int carry = 0;
    
    while(A || B){
        int sum = carry;
        if(A) sum += A->val;
        if(B) sum += B->val;
        carry = sum/10;
        ret->next = new ListNode(sum%10);
        
        if(A) A = A->next;
        if(B) B = B->next;
        ret = ret->next;
    }
    
    if(carry){
        ret->next = new ListNode(carry);
    }
    
    
    return head->next;
    
}
