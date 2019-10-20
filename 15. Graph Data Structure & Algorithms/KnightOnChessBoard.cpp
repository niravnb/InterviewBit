/*
Knight movement on a chess board

Given any source point and destination point on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ). Note that a knight cannot go out of the board.

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1

Input:

N, M, x1, y1, x2, y2
where N and M are size of chess board
x1, y1  coordinates of source point
x2, y2  coordinates of destination point
Output:

return Minimum moves or -1
Example

Input : 8 8 1 1 8 8
Output :  6

LINK: https://www.interviewbit.com/problems/knight-on-chess-board/
*/
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    int sx = C-1, sy = D-1, ex = E-1, ey = F-1;
    
    vector<vector<bool>> dp(A, vector<bool>(B,false));
    
    queue<pair<int, pair<int,int>>> q;
    q.push({0,{sx, sy}});
    dp[sx][sy]=true;
    
    int X[] = {2, 2, -2, -2 , 1, -1, 1, -1};
    int Y[] = {1, -1, 1, -1 , 2, 2, -2, -2};
        
    while(!q.empty()){
        int len = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        if(x == ex && y == ey) return len;
        
        for(int i = 0; i<8; i++){
            int newx = x + X[i];
            int newy = y + Y[i];
            
            if(newx>=0 && newx<A && newy>=0 && newy<B && dp[newx][newy]==false){
                dp[newx][newy] = true;
                q.push({len+1,{newx, newy}});
            }
        }
        
    }
    
    return -1;
}
