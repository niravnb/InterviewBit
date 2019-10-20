/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

LINK: https://www.interviewbit.com/problems/rotate-list/
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
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* ret = A, *tmp = A, *tmp2, *f;
    int c = 0;
    while(ret){
        ret = ret->next;
        c++;
    }
    
    if(B>c) B=B%c;
    
    while(B-- && tmp){
        tmp = tmp->next;
    }

    if(!tmp){
        return A;
    }else{
        tmp2 = A;
        while(tmp->next){
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
        tmp->next = A;
        ret = tmp2->next;
        tmp2->next = NULL;
        return ret;
    }
    
    return ret;
}
