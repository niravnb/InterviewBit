/*
 There are a total of N courses you have to take, labeled from 1 to N. Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2]. 
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses. return 1/0 if it is possible/not possible.
The list of prerequisite pair are given in two integer arrays B and C where B[i] is a prerequisite for C[i].

 Example: If N = 3 and the prerequisite pairs are [1,2] and [2,3], then you can finish courses in the following order: 1, 2 and 3. But if N = 2 and the prerequisite pairs are [1,2] and [2,1], then it is not possible for you to finish all the courses. 

LINK: https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
*/

int Rank[1000005];
int Parent[1000005];


int find(int x){
    if(Parent[x]!=x) Parent[x] = find(Parent[x]);
    return Parent[x];
}

void unionit(int x, int y){
    
    if(Rank[x]>Rank[y]){
        Parent[y]=x;
        Rank[x] += Rank[y];
    }else{
        Parent[x]=y;
        Rank[y] += Rank[x];
    }
}


int Solution::solve(int A, vector<int> &B, vector<int> &C) {
     if(B.size()==0||C.size()==0)
        return 1;
     
     for(int i =0 ;i <A; i++){
        Rank[i] = 1;
        Parent[i] = i;
    }
    

    for(int i = 0; i<B.size(); i++){
        if(find(B[i]-1) == find(C[i]-1)){
            return false;
        }else{
            unionit(B[i]-1,C[i]-1);
        }
        
    }
    
    return true;
}





// bool dfs(int u, vector<int> adj[], int color[])
// {
//     color[u] = 1;
 
//     for(auto x : adj[u])
//     {
//         if(color[x] == 1)
//             return true;
 
//         if(color[x] == 0 && dfs(x,adj,color))
//             return true;
//     }
 
//     color[u] = 2;
 
//     return false;
// }
 
// int Solution::solve(int A, vector<int> &B, vector<int> &C)
// {
//     vector<int> adj[A];
 
//     int n = B.size();
 
//     for(int i=0;i<n;i++)
//     {
//         int u = B[i]-1;
//         int v = C[i]-1;
//         adj[u].push_back(v);
//     }
 
//     int color[A];
//     memset(color,0,sizeof(color));
 
//     for(int i=0;i<A;i++)
//     {
//         if(color[i] == 0 && dfs(i,adj,color))
//             return 0;
//     }
 
//     return 1;
// }