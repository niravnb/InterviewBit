/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 3]
Return : 2

LINK: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
*/
int Solution::maxProfit(const vector<int> &A) {
    int res = 0, n = A.size();
    if(n==0) return 0;
    int cur_min = A[0];
    for(int i = 1;i<n;i++){
        if(A[i]>cur_min) res+=A[i]-cur_min;
        cur_min = A[i];
    }
    
    return res;
    
    
    // int n = A.size();
    //     if(n==0) return 0;

    //     vector<int> sell(n,0);

    //     sell[0] = 0;

    //     int cur_min = A[0], max_p = 0;
    //     for(int i = 1;i<n;i++){
    //         if(A[i]>cur_min){
    //             max_p = max(max_p, A[i]-cur_min);
    //         }else cur_min = A[i];
    //         sell[i] = max_p;
    //     }

    //     int cur_max = A[n-1], max_p1 = 0;
    //     for(int i = n-2;i>=0;i--){
    //         if(A[i]<cur_max){
    //             max_p1 = max(max_p1, cur_max-A[i]);
    //         }else cur_max = A[i];
    //         sell[i] += max_p1;
    //     }


    //     return *max_element(sell.begin(),sell.end());
}


// Editorial
int maxProfit(vector<int> &prices) {
    int total = 0, sz = prices.size();
    for (int i = 0; i < sz - 1; i++) {
        if (prices[i+1] > prices[i]) total += prices[i+1] - prices[i];
    }
    return total;
}
