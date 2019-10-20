/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

LINK: https://www.interviewbit.com/problems/capture-regions-on-board/
*/



// Hint:
// We already know chunks of O which remain as O are the ones which have at least one O connected to them which is on the boundary.

// Use BFS starting from ‘O’s on the boundary and mark them as ‘B’, then iterate over the whole board and mark ‘O’ as ‘X’ and ‘B’ as ‘O’.

int X[] = {0,0,1,-1};
int Y[] = {1,-1,0,0};

void dfs(vector<vector<char> > &A, vector<vector<bool>> &dp, int i, int j){
    int n = A.size(), m = A[0].size();

    dp[i][j] = true;
    
    for(int it=0;it<4;it++){
        int newX = i+X[it];
        int newY = j+Y[it];
        
        if(newX>=0 && newY>=0 && newX<n && newY<m && !dp[newX][newY] && A[newX][newY]=='O') 
        dfs(A,dp,newX,newY);
    }
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size(), m = A[0].size();
    vector<vector<bool>> dp(n,vector<bool>(m,false));
    
    for(int i =0; i<n;i++){
        if(A[i][0]=='O' && !dp[i][0]) dfs(A,dp,i,0);
        if(A[i][m-1]=='O' && !dp[i][m-1]) dfs(A,dp,i,m-1);
    }
    
    for(int i =0; i<m;i++){
        if(A[0][i]=='O' && !dp[0][i]) dfs(A,dp,0,i);
        if(A[n-1][i]=='O' && !dp[n-1][i]) dfs(A,dp,n-1,i);
    }
    
    for(int i =0; i<n;i++){
        for(int j =0; j<m;j++){
            if(A[i][j]=='O' && !dp[i][j]) A[i][j] = 'X';
        }
    }
    
    
}
