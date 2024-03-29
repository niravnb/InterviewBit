/*
As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.
Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000

Example:

Input:
    2 4 6
    2 1 3
    2 5 3

Output:
    14

Explanation: 
    First friend will take 1st and 2nd dish, second friend will take 2nd dish twice.  Thus, total cost = (5+3)+(3*2)= 14

LINK: https://www.interviewbit.com/problems/tushars-birthday-party/
*/
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int nf = A.size();
    int nd = B.size();
    
    int maxCap = *max_element(A.begin(), A.end());
    int res = 0;
    vector<vector<int>> dp(nd+1, vector<int>(maxCap+1,0));
    
    for(int i = 1; i<=maxCap; i++) dp[0][i] = INT_MAX-maxCap;

    for(int i = 1; i<=nd; i++){
        for(int j = 1; j<=maxCap;j++){
            if(B[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = min(dp[i-1][j], C[i-1]+dp[i][j-B[i-1]]);
            }
        }
    }
    
    // for(int i =0; i<=nd;i++){
    //     for(int j =0; j<=maxCap;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(auto x:A) res += dp[nd][x];
    
    return res;
    
}
