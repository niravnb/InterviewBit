/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

LINK: https://www.interviewbit.com/problems/spiral-order-matrix-ii/
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > res(A, vector<int>(A,0));
    int i = 1, r, c;
    
    for(int l = 0; l<=A/2; l++){
        r=l;
        for(c = l; c<=A-1-l; c++ ) res[r][c] = i++;
        c--;
        for(r=l+1;r<=A-1-l;r++) res[r][c] = i++;
        r--;
        for(c=A-l-2;c>=l;c--) res[r][c] = i++;
        c++;
        for(r=A-l-2;r>=l+1;r--) res[r][c] = i++;
    }
    
    return res;
    
}
