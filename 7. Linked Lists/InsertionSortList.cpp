/*
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

LINK: https://www.interviewbit.com/problems/insertion-sort-list/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    
    if(!A) return NULL;
    if(!A->next) return A;
    
    // ListNode* nodepre=NULL;
    // ListNode* node=A;
    // while(node!=NULL){
    //     ListNode *x=A;
    //     ListNode *pre= NULL;
    //     while(x!=node && node->val >= x->val){
    //         pre=x;
    //         x=x->next;
    //     }
    //     if(x!=node){
    //         nodepre->next=node->next;
    //         node->next=x;
    //         if(pre==NULL){
    //             A=node;
    //         } else
    //         pre->next=node;
    //     }
    //     nodepre=node;
    //     node=node->next;
    // }
    // return A;
    
    ListNode* p, *c, *n, *temp, *a, *cpre = NULL;
    
    c=A;
    while(c){
        a=A;
        p=NULL;
        while(a!=c && a->val<=c->val){
            p=a;
            a=a->next;
        }
        if(a!=c){
            cpre->next = c->next;
            c->next = a;
            if(p){
                p->next = c;
            }else{
                A = c;
            }
           
        }
        cpre = c;
        c=c->next;
    }
    
    return A;
    
}
/*
ListNode* Solution::insertionSortList(ListNode* A)
{
    ListNode *head = NULL;
    ListNode *temp = A;
 
    while(temp)
    {
        ListNode *nxt = temp->next;
        if(head == NULL || head->val>=temp->val)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            ListNode *curr = head;
            while(curr->next!=NULL && curr->next->val < temp->val)
                curr = curr->next;
            temp->next = curr->next;
            curr->next = temp;
        }
        temp = nxt;
    }
    return head;
}*/
