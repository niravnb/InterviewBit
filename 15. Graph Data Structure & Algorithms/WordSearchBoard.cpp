/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 
The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.

LINK: https://www.interviewbit.com/problems/word-search-board/
*/
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool dfs(vector<string> &A, string B, int i, int j, int l){
    if(l==B.length()) return true;
    int n = A.size(), m = A[0].size();

    for(int ind =0;ind<4;ind++){

        int newX =(i + X[ind]);
        int newY =(j + Y[ind]);

        if(newX>=0 && newX<n && newY>=0 && newY<m &&  A[newX][newY]==B[l]){
             if(dfs(A,B,newX,newY,l+1)) return true;
        }
    }
    
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    int n = A.size(), m = A[0].size();
    
    if(B.length()==0) return 1;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(A[i][j]==B[0]){
                if(dfs(A,B,i,j,1)) return 1;
            }
        }
    }
    
    return 0;
}
