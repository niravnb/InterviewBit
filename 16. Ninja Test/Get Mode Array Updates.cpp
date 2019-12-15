// Get Mode Array Updates

/*
You are given an array of N positive integers, A1, A2 ,…, AN.
Also, given a Q updates of form:

i j: Update Ai = j. 1 ≤ i ≤ N.
Perform all updates and after each such update report mode of the array. Therefore, return an array of Q elements, where ith element is mode of the array after ith update has been executed.

Notes

Mode is the most frequently occuring element on the array.
If multiple modes are possible, return the smallest one.
Update array input is via a Q*2 array, where each row represents a update.
For example,

A=[2, 2, 2, 3, 3]

Updates=    [ [1, 3] ]
            [ [5, 4] ]
            [ [2, 4] ]

A = [3, 2, 2, 3, 3] after 1st update.
3 is mode.

A = [3, 2, 2, 3, 4] after 2nd update.
2 and 3 both are mode. Return smaller i.e. 2.

A = [3, 4, 2, 3, 4] after 3rd update.
3 and 4 both are mode. Return smaller i.e. 3.

Return array [3, 2, 3].
Constraints
1 ≤ N, Q ≤ 105
1 ≤ j, Ai ≤ 109
*/

struct cmp{
  bool operator()(pair<int, int> a, pair<int, int> b){
      if(a.second == b.second) return a.first < b.first;
      return a.second > b.second;
  }  
};

vector<int> Solution::getMode(vector<int> &A, vector<vector<int> > &B) {
    vector<int> res;
    int n = A.size();
    int Q = B.size();
    
    set<pair<int,int>, cmp> s;
    unordered_map<int, int> mp;
    for(auto x:A){
        if(mp.find(x)==mp.end()){
            mp[x] = 1;
            s.insert({x,1});
        }else{
            auto it = mp.find(x);
            s.erase(s.find({it->first, it->second}));
            mp[x]++;
            s.insert({x,mp[x]});
        }
        
    }
    
    for(int i =0; i<Q; i++){
        int old_val = A[B[i][0]-1], new_val = B[i][1];
        
        auto it = mp.find(old_val);
        s.erase(s.find({it->first, it->second}));
        mp[old_val]--;
        
        if(mp[old_val]==0){
            mp.erase(old_val);
        }else{
            s.insert({old_val, mp[old_val]});
        }

        A[B[i][0]-1] = new_val;
        
        if(mp.find(new_val)==mp.end()){
            mp[new_val] = 1;
            s.insert({new_val,1});
        }else{
            auto it = mp.find(new_val);
            s.erase(s.find({it->first, it->second}));
            mp[new_val]++;
            s.insert({new_val,mp[new_val]});
        }
        
        res.push_back(s.begin()->first);
    }
    
    return res;
}

