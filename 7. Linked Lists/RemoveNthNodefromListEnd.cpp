/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

LINK: https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* ret = A, *tmp = A, *tmp2, *f;
    while(B-- && tmp){
        tmp = tmp->next;
    }
    if(!tmp){
        ret = A->next;
        free(A);
    }else{
        tmp2 = A;
        while(tmp->next){
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
        f = tmp2->next;
        tmp2->next = tmp2->next->next;
        free(f);
    }
    
    return ret;
}
