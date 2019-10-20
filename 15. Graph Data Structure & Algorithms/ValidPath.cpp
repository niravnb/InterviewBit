/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.


Input Format

1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
Constraints

0 <= x, y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid
For Example

Input:
    x = 2
    y = 3
    N = 1
    R = 1
    A = [2]
    B = [3]
Output:
    NO
   
Explanation:
    There is NO valid path in this case

LINK: https://www.interviewbit.com/problems/valid-path/
*/
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> dp(A+1, vector<bool>(B+1,true));
    
    for(int i =0 ;i<=A; i++){
        for(int j =0; j<=B; j++){
            for(int k = 0; k<C; k++){
                if(sqrt(pow(E[k]-i,2) + pow(F[k]-j,2)) <= D){
                    dp[i][j] = false;
                    // break;
                }
            }
        }
    }
    
    if(!dp[0][0] || !dp[A][B]) return "NO";
    
    queue<pair<int,int>> q;
    q.push({0,0});
    dp[0][0]=false;
    
    int X[] = {0, 0, 1, -1, 1, -1, -1, 1};
    int Y[] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        if(curx==A && cury==B) return "YES";
        
        for(int i =0; i<8; i++){
            int newx = curx+X[i];
            int newy = cury+Y[i];
            
            if(newx>=0 && newx<=A && newy>=0 && newy<=B && dp[newx][newy]==true){
                dp[newx][newy]=false;
                q.push({newx,newy});
            }
        }
    }
    
    return "NO";
}
