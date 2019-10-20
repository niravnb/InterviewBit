/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

LINK: https://www.interviewbit.com/problems/pascal-triangle/
*/
vector<vector<int> > Solution::solve(int A) {
    if(A == 0) return vector<vector<int> > {};
    vector<vector<int> > res(A);
    
    vector<int> temp{1};

    res[0] =  temp;
    temp.clear();
    for(int i = 1; i< A; i++){
        temp.push_back(1);
        for(int j = 1; j<i; j++){
                temp.push_back(res[i-1][j] + res[i-1][j-1]);
        }
        temp.push_back(1);
        res[i]= temp;
        temp.clear();
    }
    
    return res;
}
