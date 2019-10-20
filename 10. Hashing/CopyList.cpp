/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

LINK: https://www.interviewbit.com/problems/copy-list/
*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
// struct RandomListNode* newnode(int x){
//     struct RandomListNode* nn = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
//     nn->label = x;
//     nn->next = NULL;
//     nn->random = NULL;
//     return nn;
// }
 
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    unordered_map<RandomListNode*,RandomListNode*> m;
    RandomListNode* res, *tmp = A, *nn, *t1;
    
    res = new RandomListNode(tmp->label);
    m[tmp] = res;
    tmp = tmp->next;
    t1 = res;
    
    while(tmp){
        nn = new RandomListNode(tmp->label);
        res->next = nn;
        m[tmp] = nn;
        res = res->next;
        tmp = tmp->next;
    }
    
    nn = t1;
    tmp = A;
    while(nn){
        nn->random = m[tmp->random];
        nn = nn->next;
        tmp = tmp->next;
    }
    
    return t1;
}
