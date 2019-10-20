/*
Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

LINK: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
*/

int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    
    stack<int> s;
    
    int top, max_area = 0, i = 0;
    while(i<n){
        if(s.empty() || A[i]>=A[s.top()]) s.push(i++);
        else{
            top = s.top();
            s.pop();
            max_area = max(max_area, A[top]*(s.empty()?i:i-s.top()-1));
        }
    }
    
    while(!s.empty()){
        top = s.top();
        s.pop();
        max_area = max(max_area, A[top]*(s.empty()?i:i-s.top()-1));
    }
    
    return max_area;
}
