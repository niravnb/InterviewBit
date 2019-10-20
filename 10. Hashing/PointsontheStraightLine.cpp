/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be give 2 arrays X and Y. Each point is represented by (X[i], Y[i])

LINK: https://www.interviewbit.com/problems/points-on-the-straight-line/
*/
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    if(n<3) return n;
    int res = 0;
    int currMax, same, ver;
    
    for(int i =0;i<n;i++){
        unordered_map<string,int> m;
        currMax = same = ver = 0;
        long long x1 = A[i];
        long long y1 = B[i];
        for(int j = i+1;j<n;j++){
            long long x2 = A[j];
            long long y2 = B[j];
            
            if((x1 == x2) && (y1 == y2)) same++;
            else if(x1==x2) ver++;
            else{
                long long s1 = (y2-y1);
                long long s2 = (x2-x1);
                long long g = __gcd(s1,s2);
                string tmp = to_string(s1/g) + "_" +  to_string(s2/g);
                m[tmp]++;
                currMax = max(currMax,m[tmp]);
            }
            currMax = max(currMax,ver);
        }
        
        res = max(res,currMax+same+1);
    }
    return res;
        
}
