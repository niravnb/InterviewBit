/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2

LINK: https://www.interviewbit.com/problems/2-sum/
*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> res;
    unordered_map<int,int> m;
    m.insert({A[0],0});
    int rem = 0,i1,i2;
    
    for(int i =1;i<A.size();i++){
        rem = B - A[i];
        if(m.find(rem)!=m.end()){
            i1 = m[rem]+1;
            i2 = i+1;
            
            res.push_back(i1);
            res.push_back(i2);
            return res;
        }else{
            m.insert({A[i],i});
        }
    }
    
    return res;
}
