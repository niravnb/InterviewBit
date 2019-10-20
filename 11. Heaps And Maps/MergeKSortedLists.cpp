/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

LINK: https://www.interviewbit.com/problems/merge-k-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
struct compare{
    bool operator()(const ListNode* a , const ListNode* b){
        return a->val > b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* res=NULL, *tmp= NULL, *final;
    int k = A.size(), key, val;

    priority_queue<ListNode*, vector<ListNode*>, compare > m; 
    
    for(int i = 0; i<k;i++) m.push(A[i]);
    
    int first = 1;
 
    while (m.empty() == false) 
    { 
        ListNode* t = m.top();
        key = t->val;
        tmp = new ListNode(key);
        if(first){
            res = tmp;
            first = 0;
            final = res;
        }else{
            res->next = tmp;
            res = res->next;
        }
        m.pop();

        if(t->next){
            t = t->next;
            m.push(t);
        }

    }
    return final;
}
