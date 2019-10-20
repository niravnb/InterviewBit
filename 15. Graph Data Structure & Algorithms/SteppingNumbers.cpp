/*
Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 
Return the numbers in sorted order.

LINK: https://www.interviewbit.com/problems/stepping-numbers/
*/
void dfs(vector<int> &res, int A, int B, int i){
    queue<int> q;
    q.push(i);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur>=A && cur<=B) res.push_back(cur);

        if(cur==0 || cur>B) continue;
        
        int lastdigit = cur%10;
        int child1 = cur*10 + lastdigit+1;
        int child2 = cur*10 + lastdigit-1;
        
        if(lastdigit==0) q.push(child1);
        else if(lastdigit == 9) q.push(child2);
        else{
            q.push(child1);
            q.push(child2);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    
    if(B<A) return res;
    
    for(int i = 0; i<= 9; i++) dfs(res,A,B,i);
    
    sort(res.begin(), res.end());
    
    return res;
    
}
