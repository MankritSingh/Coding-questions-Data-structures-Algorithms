/*Question:given stock price of consecutive days,tell the max profit that can be achieved by buying and selling a single stock
Analysis:It is a very easy question.It isnt general DP but the approach of dp of saving/remebering data is used here in from of remebering the maxval and maxprofit
*/

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    int maxval=prices[n-1];
    int profit=0;
    for(int i=n-2;i>=0;i--){
        if(maxval<prices[i]){
            maxval=prices[i];
        }
        else{
            profit=max(profit,(maxval-prices[i]));
        }
    }
    return profit;
}
