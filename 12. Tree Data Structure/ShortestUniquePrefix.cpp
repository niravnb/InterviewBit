/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 

LINK: https://www.interviewbit.com/problems/shortest-unique-prefix/
*/
#define MAX 26

struct tries{
    int freq;
    struct tries *child[MAX];
};

struct tries* createtrie(void){
    struct tries* tmp = new tries;
    tmp->freq = 1;
    for(int i = 0;i<MAX;i++){
        tmp->child[i]=NULL;
    }
    return tmp;
}

void insert(struct tries* r, string s){
    int l = s.length();
    
    for(int i = 0; i<l;i++){
        int tmp = s[i]-'a';
        if(r->child[tmp]==NULL){
            struct tries* t = createtrie();
            r->child[tmp] = t;
        }else{
         (r->child[tmp]->freq)++;   
        }
        r = r->child[tmp];
    }
}

string findprefix(struct tries* r, string s){
    
    if(!r) return "";
    
    string tmp=  "";
    int l = s.length();
    
    for(int i = 0; i<l;i++){
        tmp +=(s[i]);
        if(r->child[s[i]-'a']->freq==1){
            break;
        }
        r = r->child[s[i]-'a'];
    }
    
    return tmp;
}


vector<string> Solution::prefix(vector<string> &A) {
    
    if(A.size()==0) return {};
    
    struct tries* r = createtrie();
    r->freq=0;
    
    for(int i =0; i<A.size();i++){
        insert(r,A[i]);
    }
    
    vector<string> res;
    
    for(int i =0; i<A.size();i++){
        res.push_back(findprefix(r,A[i]));
    }
    
    return res;
}
