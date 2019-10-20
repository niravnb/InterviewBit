/*
Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]

LINK: https://www.interviewbit.com/problems/hotel-reviews/
*/

/////////////////////////////////////////////////////////////
// Using Trie
/////////////////////////////////////////////////////////////
#define MAX 26

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    if(a.first == b.first) return a.second < b.second;
        return (a.first > b.first);
} 


struct trie{
    bool end;
    struct trie* child[MAX];
};

struct trie* newNode(){
    struct trie* tmp = new trie;
    tmp->end = false;
    for(int i = 0; i<MAX;i++)
        tmp->child[i] = NULL;
    
    return tmp;
}

void insert(struct trie* r, string s){
    int l = s.length();
    
    for(int i =0; i<l;i++){
        int ind = s[i]-'a';
        if(!r->child[ind])
            r->child[ind] = newNode();
            
        r = r->child[ind];
    }
    r->end = true;
}

bool search(struct trie* r, string s){
    int l = s.length();
    
    for(int i =0; i<l;i++){
        int ind = s[i]-'a';
        if(!r->child[ind])
            return false;
            
        r = r->child[ind];
    }
    
    return r->end;
}


vector<int> Solution::solve(string A, vector<string> &B) {
    struct trie* t = newNode();
    t->end = false;
    for(int i = 0, j = 0; i<A.length();i++){
        if(A[i]=='_' || i==A.length()-1){
            string test;
            if (A[i]=='_') test = A.substr(j,i-j);
            else test = A.substr(j,i-j+1);
            
            insert(t,test);
            j = i+1;
        }
        
    }
    vector<pair<int,int>> res;
    for(int k = 0; k<B.size();k++){
        string A = B[k];
        int count = 0;
        for(int i = 0, j = 0; i<A.length();i++){
            if(A[i]=='_' || i==A.length()-1){
                string test;
                if (A[i]=='_') test = A.substr(j,i-j);
                else test = A.substr(j,i-j+1);
                
                bool found = search(t,test);
                j = i+1;
                if(found) count++;
                // cout << test << " " << found << endl;
            }
        }
        res.push_back(make_pair(count,k));
    }
    
    sort(res.begin(),res.end(),sortbysec); 

    vector<int> ret;
    for(int i =0; i<res.size();i++){
        // cout << res[i].first << " " << res[i].second << endl;
        ret.push_back(res[i].second);
    }
    
    return ret;
    
}
