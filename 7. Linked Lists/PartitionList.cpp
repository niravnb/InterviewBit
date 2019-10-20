/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

LINK: https://www.interviewbit.com/problems/partition-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* l, *r;
    
    ListNode* lhead = new ListNode(0);
    ListNode* rhead = new ListNode(0);

    l = lhead;
    r = rhead;
    
    while(A){
        if(A->val<B){
            l->next = A;
            l = l->next;
        }else{
            r->next = A;
            r = r->next;
        }
        A = A->next;
    }
    
    // if(!(lhead->next)) return rhead->next;
    // if(!(lhead->next)) return lhead->next;
    
    l->next = rhead->next;
    r->next = NULL;
    
    return lhead->next;
    
}
