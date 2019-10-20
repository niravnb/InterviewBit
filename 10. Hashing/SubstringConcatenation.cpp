/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

LINK: https://www.interviewbit.com/problems/substring-concatenation/
*/
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
        string s = A;
        vector<string> words = B;
        vector<int> res;
        
        if(s.size()==0 || words.size()==0) return res;
        int w = words[0].size();
        int n = words.size();
        
        
        int k = w*n;
        
        if(k==0) return res;
        if(k>s.size()) return res;
        
        unordered_map<string,int> m;
        for(int i=0;i<n;i++) m[words[i]]++;
        
        for(int i=0;i<=s.size()-k;i++){
            unordered_map<string,int> tm(m);
            
            int j = i;
            int count = n;
            while(j<i+k){
                string ts = s.substr(j,w);
                
                if(tm.find(ts)==tm.end() || tm[ts]==0)
                    break;
                else{
                    tm[ts]--;
                    count--;
                }
                
                j += w;
            }
            
            if(!count) res.push_back(i);
            

        }
        
        return res;
}
