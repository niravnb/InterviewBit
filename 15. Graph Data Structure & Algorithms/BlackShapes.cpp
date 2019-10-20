/*
Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.

LINK: https://www.interviewbit.com/problems/black-shapes/
*/
void sol(vector<string>& A, int i, int j){
    int m = A.size(), n = A[0].size();
    
    if(i>=m || i<0 || j>=n || j<0) return;
    if(A[i][j]!='X') return;
    A[i][j] = 'O';
    sol(A,i,j+1);
    sol(A,i,j-1);
    sol(A,i+1,j);
    sol(A,i-1,j);
    
}

int Solution::black(vector<string> &A) {
    int m = A.size(), res = 0;
    
    for(int i = 0; i<m;i++){
        for(int j =0; j<A[i].size();j++){
            if(A[i][j]=='X'){
                res++;
                sol(A,i,j);
            }
        }
    }
    
    return res;
    
}
