/*
There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Sample Input :

Ratings : [1 2]
Sample Output :

3
The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. So rating 2 candidate gets 2 candies. In total, 2+1 = 3 candies need to be given out.

LINK: https://www.interviewbit.com/problems/distribute-candy/
*/

int Solution::candy(vector<int> &A) {
    // O(n)
    int n  = A.size();
    vector<int> count(n,1);
    
    for(int i = 1; i<n; i++){
        if(A[i]>A[i-1]){
            count[i] = max(count[i],count[i-1]+1);
        }
    }
    
    for(int i = n-2; i>=0; i--){
        if(A[i]>A[i+1]){
            count[i] = max(count[i],count[i+1]+1);
        }
    }
    
    int res = 0;
    for(auto x : count) res+=x;
    
    return res;
    
    
    
    // O(nlogn)
    // int n = A.size();
    // vector<pair<int,int>> m;
    // map<int,int> mm;

    // for(int i =0; i<n; i++){
    //     m.push_back({A[i],i});
    //     mm.insert({i,1});
    // }
    
    // sort(m.begin(),m.end());
    // int res = 0;
    
    // for(auto i = m.begin(); i!=m.end(); i++){

    //     int rating = (*i).first;
    //     int ind = (*i).second;
    //     int candy = mm[ind];
        
    //     if(ind+1<n && A[ind+1]<A[ind]){
    //         candy = mm[ind+1] + 1;
    //     }
    //     if(ind-1>=0 && A[ind-1]<A[ind]){
    //         candy = max(candy, mm[ind-1] + 1);
    //     }
    //     mm[ind] = candy;
    //     res += candy;
    // }
    
    // return res;
    
}
