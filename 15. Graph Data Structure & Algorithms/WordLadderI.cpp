/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

You must change exactly one character in every transformation
Each intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note that we account for the length of the transformation path instead of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

LINK: https://www.interviewbit.com/problems/word-ladder-i/
*/

struct myword{
    string w;
    int len;
};
    
bool match(string a, string b){
    int count = 0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]) count++;
    
        if(count>1) return false;
    }
    return count<=1?true:false;
}

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    set<string> wl;
    for(auto s:dictV){
        wl.insert(s);
    }
    
    queue<myword> q;
    q.push({start, 1});
    
    while(!q.empty()){
        myword tmp = q.front();
        q.pop();
        
        if(tmp.w==end) return tmp.len;
        
        for(auto it:wl){
            if(match(tmp.w,it)){
                q.push({it, tmp.len+1});
                wl.erase(it);
            }
        }
    }
    
    return 0;
    
}




// struct node {
//         string val;
//         int depth;
//     };
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
//         unordered_set<string> wl;
//         for(auto s:wordList){
//             wl.insert(s);
//         }
        
//         queue<node> q;
//         q.push({beginWord, 1});
//         while (!q.empty()) {
//             node tmp = q.front();
//             q.pop();
//             string tmpString;
//             for (char c = 'a'; c <= 'z'; ++c) {
//                 for (int i = 0; i < tmp.val.length(); ++i) {
//                     tmpString = tmp.val;
//                     tmpString[i] = c;
//                     if (tmpString != tmp.val && wl.find(tmpString) != wl.end()) {
//                         if(tmpString==endWord) return tmp.depth+1;
//                         q.push({tmpString, tmp.depth + 1});
//                         wl.erase(tmpString);
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
