/*
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
 Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

LINK: https://www.interviewbit.com/problems/word-ladder-ii/
*/
int minLen;
    
bool match(string a, string b){
    int c = 0;
    for(int i =0; i<a.length();i++){
        if(a[i]!=b[i]) c++;
        
        if(c>1) return false;
    }
    return c==1?true:false;
}

void dfs(string e, vector<string>& dict, vector<vector<string>> &res, vector<string> &tmp, vector<bool> &vis){

    if(tmp.size()>minLen) return;
    
    if(tmp.back()==e){
        if(tmp.size()<minLen){
            minLen = tmp.size();
            res.clear();
        }
        res.push_back(tmp);
        return;
    }
    
    int n = dict.size();
    for(int i =0; i<n;i++){
        if(!vis[i] && match(tmp.back(),dict[i])){
            vis[i] = true;
            tmp.push_back(dict[i]);
            dfs(e,dict,res,tmp,vis);
            tmp.pop_back();
            vis[i] = false;
        }
    }
    
    
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    dict.push_back(end);

    unordered_set<string> s;
    for(auto x:dict) s.insert(x);
        
    dict.assign(s.begin(),s.end());
    sort(dict.begin(),dict.end());
        
    vector<vector<string>> res;
    vector<string> tmp;
    tmp.push_back(start);
    
    int n = dict.size();
    vector<bool> vis(n,false);
    
    minLen = INT_MAX;
    
    dfs(end, dict, res, tmp, vis);
    
    return res;
    
}
