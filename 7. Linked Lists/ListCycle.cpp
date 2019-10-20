/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

LINK: https://www.interviewbit.com/problems/list-cycle/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *s = A, *f = A;
    
    while(s && f && f->next){
        s = s->next;
        f = f->next->next;
        if(s==f) break;
    }
    
    if(s!=f) return NULL;
    
    s = A;
    while(s!=f){
        s = s->next;
        f = f->next;
    }

    return s;
    
}
