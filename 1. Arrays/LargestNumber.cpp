/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

LINK: https://www.interviewbit.com/problems/largest-number/
*/

bool comp(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    
    string t1 = sa+sb;
    string t2 = sb+sa;
    return t1>t2;
}

string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> v;
    for(auto x:A) v.push_back(x);
    
    sort(v.begin(),v.end(),comp);
    
    string res = "";
    int c = 0;
    for(auto x:v){
        res += to_string(x);
        if(x==0) c++;
    }
    
    if(c==res.length()) return "0";
    
    return res;
}
