/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

LINK: https://www.interviewbit.com/problems/anti-diagonals/
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > res;
    vector<int> tmp;
    
    int i,j;
    for(j=0;j<n;j++){
        int jj = j;
        for(i=0;i<=j;i++){
            tmp.push_back(A[i][jj--]);
        }
        res.push_back(tmp);
        tmp.clear();
    }
    
    for(i=1;i<n;i++){
        int ii = i;
        for(j=n-1;j>=i;j--){
           tmp.push_back(A[ii++][j]);
        }
        res.push_back(tmp);
        tmp.clear();
    }
    
    return res;
}



/*
Editorial:

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    int N = 2*(n-1) + 1;//number of vectors in ans
    vector<vector<int>> ans(N);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            ans[i+j].push_back(A[i][j]);//sum of index values in 2d array gives the index in ans
    }
    return ans;
}

*/
