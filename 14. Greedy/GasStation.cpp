/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2..
Completing the circuit means starting at i and ending up at i again.

Example :

Input :
      Gas :   [1, 2]
      Cost :  [2, 1]

Output : 1 

If you start from index 0, you can fill in gas[0] = 1 amount of gas. Now your tank has 1 unit of gas. But you need cost[0] = 2 gas to travel to station 1. 
If you start from index 1, you can fill in gas[1] = 2 amount of gas. Now your tank has 2 units of gas. You need cost[1] = 1 gas to get to station 0. So, you travel to station 0 and still have 1 unit of gas left over. You fill in gas[0] = 1 unit of additional gas, making your current gas = 2. It costs you cost[0] = 2 to get to station 1, which you do and complete the circuit. 

LINK: https://www.interviewbit.com/problems/gas-station/
*/
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {

    int ind=0, curr_gas = 0, total=0;
    int n = A.size();
    
    for(int i =0; i<n;i++){
        total += A[i] - B[i];
        curr_gas += A[i] - B[i];
        if(curr_gas < 0){
            ind = i+1;
            curr_gas = 0;
        }
    }
    
    return (total<0 ||ind==n)?-1:ind;


    // int ind=0, curr_gas = 0, total_gas = 0, total_cost = 0;
    // int n = A.size();
    
    // for(int i =0; i<n;i++){
    //     total_gas += A[i];
    //     total_cost += B[i];
    //     curr_gas += A[i] - B[i];
    //     if(curr_gas < 0){
    //         ind = i+1;
    //         curr_gas = 0;
    //     }
    // }
    
    // return (curr_gas<0 || total_gas<total_cost)?-1:ind;
    
}
