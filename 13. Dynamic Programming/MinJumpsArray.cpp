/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example :
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

If it is not possible to reach the end index, return -1.

LINK: https://www.interviewbit.com/problems/min-jumps-array/
*/

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n<=1) return 0;
    if(A[0]==0) return -1;
    
    int maxReach = A[0], stepsLeft = A[0], jumps = 1;
    
    for(int i = 1;i<n-1;i++){   //Why i<n-1 ? 
        maxReach = max(maxReach, i+A[i]);
        stepsLeft--;
        if(stepsLeft == 0){
            jumps++;
            if(i>=maxReach) return -1;
            stepsLeft = maxReach - i;
        }
    }
    
    return jumps;
}


// Editorial
class Solution {
    public:
        int jump(int A[], int n) {
            if(n <= 1){
                return 0;
            }
            int maxReachPos = A[0];
            int curMaxReachPos = A[0];
            int curStep = 1;
            for(int i = 1; i <= maxReachPos; i++){
                if(i == n - 1){
                    return curStep;
                }
                curMaxReachPos = max(curMaxReachPos, i + A[i]);
                if(i == maxReachPos){
                    if (curMaxReachPos <= i) return -1;
                    maxReachPos = curMaxReachPos;
                    curStep++;
                }
            }
            return -1;
        }
};