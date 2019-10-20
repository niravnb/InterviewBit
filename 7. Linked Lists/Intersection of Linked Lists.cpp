/*Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

 Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* temp = NULL , *ta = NULL, *tb = NULL;
    int a = 0, b = 0;

    temp = A;
    while(temp){
        a++;
        temp = temp->next;
    }
    temp = B;
    while(temp){
        b++;
        temp = temp->next;
    }
    temp = NULL;
    if(a==0 || b==0) return temp;
    ta = A;
    tb = B;
    if(a>b){
        for(int i = 0; i< a-b; i++) ta = ta->next;
    }else if(b>a){
        for(int i = 0; i< b-a; i++) tb = tb->next;
    }
    
    while(ta && tb && ta != tb){
        ta = ta->next;
        tb = tb->next;
    }
    
    
    return ta;
    
}
