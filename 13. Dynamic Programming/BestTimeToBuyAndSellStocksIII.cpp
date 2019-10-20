/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 1 2]
Output : 2

Explanation : 
  Day 1 : Buy 
  Day 2 : Sell
  Day 3 : Buy
  Day 4 : Sell

LINK: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/
*/
int Solution::maxProfit(const vector<int> &A) {
    
        int n = A.size();
        if(n==0) return 0;

        vector<int> sell(n,0);

        sell[0] = 0;

        int cur_min = A[0], max_p = 0;
        for(int i = 1;i<n;i++){
            if(A[i]>cur_min){
                max_p = max(max_p, A[i]-cur_min);
            }else cur_min = A[i];
            sell[i] = max_p;
        }

        int cur_max = A[n-1], max_p1 = 0;
        for(int i = n-2;i>=0;i--){
            if(A[i]<cur_max){
                max_p1 = max(max_p1, cur_max-A[i]);
            }else cur_max = A[i];
            sell[i] += max_p1;
        }


        return *max_element(sell.begin(),sell.end());
        
        
        // int x = prices.size();
        // if(x==0){
        //     return 0;
        // }
        // int n = min(2,x);
        // vector<int> buy(n,INT_MAX);
        // vector<int> sell(n,INT_MIN);
        
        // for(auto &price: prices) {
        //     for(int i=0; i<n; i++) {
        //         buy[i] = min(buy[i], (i==0?price:price-sell[i-1]));
        //         sell[i] = max(sell[i], price-buy[i]);
        //     }
        // }
        
        // return sell[n-1];
}
