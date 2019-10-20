/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.' 
You may assume that there will be only one unique solution.



A sudoku puzzle,



and its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

LINK: https://www.interviewbit.com/problems/sudoku/
*/
bool check(vector<vector<char> > &A, int r, int c){
 
    for(int i =0; i<9;i++){
        if(r!=i && A[r][c]==A[i][c]) return false;
        if(c!=i && A[r][c]==A[r][i]) return false;
    }
    
    int nr = (r/3)*3;
    int nc = (c/3)*3;
    
    for(int i =0;i<3; i++){
        for(int j=0;j<3;j++){
            int newi = i + nr;
            int newj = j + nc;
            if(r!=newi && c!=newj && A[r][c]==A[newi][newj]) return false;
        }
    }
    return true;
    
}

bool solve(vector<vector<char> > &A, int r, int c){
    if(c==9){
        c=0;
        r++;
    }
    if(r==9) return true;
    
    // cout << r << " " << c << " " << A[r][c] << endl;
    
    if(A[r][c]!='.'){
        bool flag = solve(A,r,c+1);
        if(flag) return true;
    }
    else{
        for(int i = 1; i<=9; i++){
            A[r][c] = (i+'0');
            if(check(A,r,c)){
                bool flag = solve(A,r,c+1);
                if(flag) return true;
        }
            A[r][c] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    solve(A,0,0);
}
