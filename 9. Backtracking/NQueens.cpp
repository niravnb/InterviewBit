/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

LINK: https://www.interviewbit.com/problems/nqueens/
*/


// fixing one queen in one column
bool isSafe(vector<vector<string> > &res, int n, int r, int c){
    
    for(int i = 0;i<c;i++){
        if(res[r][i]=="Q") return false;
    }
    
    for(int i = r, j = c;i>=0 && j>=0;i--,j--){
        if(res[i][j]=="Q") return false;
    }
    
    for(int i = r, j = c; i<n && j>=0;i++,j-- ){
        if(res[i][j]=="Q") return false;
    }
    
    return true;
}

void mySolver(vector<vector<string> > &final, vector<vector<string> > &res, int n, int c){
    if(c>=n){
        vector<string> aux;
        for(int i=0;i<n;i++){
            string s;
            for(int j = 0; j<n;j++){
                s.append(res[i][j]);
            }
            aux.push_back(s); 
        }
        final.push_back(aux);
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(res,n,i,c)){
            res[i][c] = "Q";
            mySolver(final, res,n,c+1);
            res[i][c] = ".";
        }
    }

}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==1) return {{"Q"}};
    vector<vector<string> > final, res(A, vector<string>(A,"."));
    mySolver(final, res, A, 0);
    
    return final;
}



// Fixing 1 queen in 1 row
// vector<vector<string> > res;
 
// bool check(vector<string> &temp, int row, int col, int A)
// {
//     for(int i=0;i<row;i++)
//         if(temp[i][col]=='Q')
//             return false;
 
//     for(int i=row, j=col; i>=0 && j>=0;i--, j--)
//         if(temp[i][j]=='Q')
//             return false;
 
//     for(int i=row, j=col; i>=0 && j<A;i--, j++)
//         if(temp[i][j]=='Q')
//             return false;
 
//     return true;
// }
 
// void getNQueen(int A, int row, vector<string> &temp)
// {
//     if(row == A)
//     {
//         res.push_back(temp);
//         return;
//     }
 
//     for(int col=0;col<A;col++)
//     {
//         if(check(temp, row, col, A))
//         {
//             temp[row][col] = 'Q';
//             getNQueen(A, row+1, temp);
//             temp[row][col] = '.';
//         }
//     }
// }
 
// vector<vector<string> > Solution::solveNQueens(int A)
// {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
//     res.clear();
 
//     if(A==2 || A==3)
//         return res;
 
//     string s(A,'.');
 
//     vector<string> temp(A,s);
 
//     getNQueen(A, 0, temp);
 
//     return res;
// }
