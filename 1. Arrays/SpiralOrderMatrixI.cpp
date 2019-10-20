/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]

LINK: https://www.interviewbit.com/problems/spiral-order-matrix-i/
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    
    vector<int> B;
    int i = 0, j = 0;
    int tr = 0, rc = 0, br = 0, lc = 0;
    for(int count = 0; count < m*n;){
        
        while(j<n-lc && count < m*n ){
            B.push_back(A[i][j]);
            count++;
            j++;
        }
        tr++;
        j--;
        i++;
        while(i<m-br && count < m*n){
            B.push_back(A[i][j]);
            count++;
            i++;
        }
        i--;
        j--;
        rc++;
        while(j>=lc && count < m*n){
            B.push_back(A[i][j]);
            count++;
            j--;
        }
        j++;
        i--;
        br++;
        while(i>=tr && count < m*n){
            B.push_back(A[i][j]);
            count++;
            i--;
        }
        i++;
        j++;
        lc++;
        
    
        
        
    }
    return B;
}
