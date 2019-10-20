/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

LINK: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
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
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode*curr = A, *p = NULL;
    ListNode* head = new ListNode(0);
    head->next = A;
    p = head;
    while(curr){
        while(curr->next && curr->val == curr->next->val) curr = curr->next;
        
        if(p->next == curr) p = p->next;
        else p->next = curr->next;
        
        curr = curr->next;
    }
    
    return head->next;
    
    // ListNode* ret = A, *tmp = A, *f, *p = NULL;
    
    // while(tmp && tmp->next){
    //     if(tmp->val == tmp->next->val){
    //         int dup = tmp->val;
    //         while(tmp && tmp->val == dup){
    //             f = tmp;
    //             tmp = tmp->next;
    //             free(f);
    //         }
    //         if(!p) ret = tmp;
    //         else p->next = tmp;
    //     }else{
    //         p = tmp;
    //         tmp = tmp->next;
    //     }
    // }
    // if(ret) return ret;
    // else return NULL;
    // // return ret;
}
