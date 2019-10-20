/*
You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:

Returned string should not contain leading zeroes.
For example,

For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.

LINK: https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
*/
string Solution::multiple(int A) {
    
    vector<int> digit(A+1, -1);
    vector<int> parent(A+1, -1);
    vector<bool> visited(A+1, 0);
    
    int rem = 1%A, num, i;
    digit[rem] = 1;
    parent[rem] = -1;
    visited[rem] = 1;
    
    queue<int> q;
    q.push(rem);
    
    while(!q.empty()){
        num = q.front();
        q.pop();
        
        if(num==0){
            break;
        }else{
            int n0 = ((num*10) + 0)%A;
            int n1 = ((num*10) + 1)%A;
            
            if(!visited[n0]){
                visited[n0]=1;
                parent[n0]=num;
                digit[n0]=0;
                q.push(n0);
            }
            if(!visited[n1]){
                visited[n1]=1;
                parent[n1]=num;
                digit[n1]=1;
                q.push(n1);
            }
            
        }
    }
    
    string res = "";
    while(num!=-1){
        if(digit[num]==1) res = "1"+res;
        else if (digit[num]==0) res = "0"+res;
        num = parent[num];
    }
    
    return res;

    
}


// TLE

// int mod(string t, int n){
//     int res = 0;
//     for(int i =0; i<t.length();i++){
//         res = res*10 + (t[i]-'0');
//         res = res%n;
//     }
//     return res;
// }

// string Solution::multiple(int A) {
//     queue<string> q;
//     set<int> s;
//     q.push("1");
    
//     string res;
    
//     while(!q.empty()){
//         string t = q.front();
//         q.pop();
        
//         int rem = mod(t,A);
//         if(rem == 0) return t;
//         else if(s.find(rem)==s.end()){
//             s.insert(rem);
//             q.push(t+"0");
//             q.push(t+"1");
//         }
//     }
    
//     return res;
// }
