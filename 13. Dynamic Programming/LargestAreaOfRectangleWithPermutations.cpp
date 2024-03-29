/*
Given a binary grid i.e. a 2D grid only consisting of 0’s and 1’s, find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them. You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid. Please follow the below example for more clarity.

Lets say we are given a binary grid of 3 * 3 size.

1 0 1

0 1 0

1 0 0

At present we can see that max rectangle satisfying the criteria mentioned in the problem is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it. Now since we are allowed to permutate the columns of the given matrix, we can take column 1 and column 3 and make them neighbours. One of the possible configuration of the grid can be:

1 1 0

0 0 1

1 0 0

Now In this grid, first column is column 1, second column is column 3 and third column is column 2 from the original given grid. Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2 which is bigger than the earlier case. Hence 2 will be the answer in this case.

LINK: https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
*/


// Editorial
int Solution::solve(vector<vector<int> > &mat) {
    int R = mat.size();
    int C = mat[0].size();
    int hist[R+1][C+1];
 
    // Step 1: Fill the auxiliary array hist[][]
    for (int i=0; i<C; i++)
    {
        // First row in hist[][] is copy of first row in mat[][]
        hist[0][i] = mat[0][i];
 
        // Fill remaining rows of hist[][]
        for (int j=1; j<R; j++)
            hist[j][i] = (mat[j][i]==0)? 0: hist[j-1][i]+1;
    }
 
 
    // Step 2: Sort rows of hist[][] in non-increasing order
    for (int i=0; i<R; i++)
    {
        vector<int>count(R+1,0);
 
        // counting occurrence
        for (int j=0; j<C; j++)
            count[hist[i][j]]++;
 
        //  Traverse the count array from right side
        int col_no = 0;
        for (int j=R; j>=0; j--)
        {
            if (count[j] > 0)
            {
                for (int k=0; k<count[j]; k++)
                {
                    hist[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
 
    // Step 3: Traverse the sorted hist[][] to find maximum area
    int curr_area, max_area = 0;
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
        {
            // Since values are in decreasing order,
            // The area ending with cell (i, j) can
            // be obtained by multiplying column number
            // with value of hist[i][j]
            curr_area = (j+1)*hist[i][j];
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}


// My code

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    // vector<vector<int> > dp(n, vector<int>(m,0));
    // int dp[n][m];
    // for(int i =0; i<m;i++){
    //     for(int j =0;j<n;j++){
    //         if(A[j][i]==1){
    //          if(j==0) dp[j][i] = 1 ;
    //          else dp[j][i] = 1 + dp[j-1][i];
    //         }else dp[j][i] = 0;
    //     }
    // }
    
    int R = n, C = m;
    int dp[R+1][C+1];
 
    // Step 1: Fill the auxiliary array hist[][]
    for (int i=0; i<m; i++)
    {
        // First row in hist[][] is copy of first row in mat[][]
        dp[0][i] = A[0][i];
 
        // Fill remaining rows of hist[][]
        for (int j=1; j<R; j++)
            dp[j][i] = (A[j][i]==0)? 0: dp[j-1][i]+1;
    }
 
    
    for(int i =0; i<n;i++){
        int count[n+1];
        memset(count,0,sizeof(count));

        for(int j=0;j<m;j++) count[dp[i][j]]++;
        int ind = 0;
        for(int j = m;j>=0;j--){
            if(count[j]>0){
                for (int k = 0; k < count[j]; k++) { 
                    dp[i][ind] = j;
                    ind++;
                }
            }
        }
    }
    
    int maxArea = 0, currArea = 0;
    for(int j = 0; j<n;j++){
        for(int i =0; i<m;i++){
            currArea = (i+1)*dp[j][i];
            maxArea = max(maxArea,currArea);
        }
    }

    return maxArea;
}




