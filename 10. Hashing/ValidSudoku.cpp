/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/valid-sudoku/
*/
bool check(const vector<string> &A, int r, int c){
    
    for(int i =0;i<9;i++){
        if(r!=i && A[r][c]==A[i][c]) return false;
        if(c!=i && A[r][c]==A[r][i]) return false;
    }
    
    int nr = (r/3)*3;
    int nc = (c/3)*3;
    
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            int newr = nr + i;
            int newc = nc + j;
            if(newr!=r && newc!=c && A[r][c]==A[newr][newc]) return false;
        }
    }
    
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            if(A[r][c]!='.'){
                if(!check(A,r,c)){
                    return false;
                }
            }
        }
    }
    
    return true;
}
