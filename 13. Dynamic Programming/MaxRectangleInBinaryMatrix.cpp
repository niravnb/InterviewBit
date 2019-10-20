/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

LINK: https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
*/
int maxHist(vector<int> &A){
    int n = A.size(), top, area = 0, i =0;
    
    stack<int> s;
    while(i<n){
        if(s.empty() || A[i]>=A[s.top()]) s.push(i++);
        else{
            top = s.top();
            s.pop();
            area = max(area, A[top]*(s.empty()?i:i-s.top()-1));
        }
    }
    
    while(!s.empty()){
        top = s.top();
        s.pop();
        area = max(area, A[top]*(s.empty()?i:i-s.top()-1));
    }
    
    return area;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int max_area = maxHist(A[0]);
    
    
    for(int i = 1; i<A.size();i++){
        for(int j =0; j<A[i].size();j++){
            if(A[i][j]) A[i][j] += A[i-1][j];
        }
        max_area = max(max_area, maxHist(A[i]));
    }
    
    return max_area;
}
