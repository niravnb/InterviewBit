/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

LINK: https://www.interviewbit.com/problems/merge-overlapping-intervals/
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmpfun(const Interval &a, const Interval &b){
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    vector<Interval> res;
    if(n < 1) return res;
    if(n == 1) {
        res.push_back(Interval(A[0].start,A[0].end));
        return res;
    }
    sort(A.begin(), A.end(), cmpfun);
    
    int i = 0, a, b, c, d;
    res.push_back(Interval(A[0].start,A[0].end));
    for(int j = 0, i = 1; i<n; i++){
        a = res[j].start;
        b = res[j].end;
        c = A[i].start;
        d = A[i].end;
        
        if(c > b){
            res.push_back(Interval(c,d));
            j++;
        }else{
            if(b<d){
                res[j].end = d;
            }
        }
    }
    return res;
}
