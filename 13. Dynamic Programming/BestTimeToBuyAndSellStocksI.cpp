/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example :

Input : [1 2]
Return :  1

LINK: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
*/
int Solution::maxProfit(const vector<int> &A) {
        
    vector<int> prices = A;
    int n = prices.size();
    
    if(n==0) return 0;
    
    int cur_min = prices[0], max_profit = 0;
    
    for(int i =1;i<n;i++){
        if(prices[i]>cur_min){
            max_profit = max(max_profit,prices[i]-cur_min);
        }else cur_min = prices[i];
    }
    return max_profit;
}
