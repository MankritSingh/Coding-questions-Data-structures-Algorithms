/*Question:Given value of stocks for a number of days,find the max profit that can be earned.We can buy and sell any number of times

Analysis:This problem can be solved with dp and greedy
DP:For each day we have 2 optons,buy or sell.Now we cant buy stock if we already have one and we can sell if we have no stock so we keep a variable canBuy.


Greedy:This says that we can just buy and sell each day to acculate the profit and simply get the max profit.

*/
//DP
#include <bits/stdc++.h>
int len;
long sol(long *values, int n,int canBuy,vector<vector<long>>&dp){
    if(n==len)    return 0;
    //2 cases buy or sell
    //1 buy
    if(dp[n][canBuy]!=-1)    return dp[n][canBuy];
    long profit=0;
    if(canBuy){
        long buystock=-values[n]+sol(values,n+1,0,dp);
        long dontbuy=0+sol(values,n+1,1,dp);
        profit=max(buystock,dontbuy);
    }
    //sell stock
    else{
        long sellstock=values[n]+sol(values,n+1,1,dp);
        long dontsell=0+sol(values,n+1,0,dp);
        profit=max(sellstock,dontsell);
    }
    return dp[n][canBuy]=profit;
}

long getMaximumProfit(long *values, int n)
{len=n;
 vector<vector<long>>dp(n,vector<long>(2,-1));
 
    return sol(values,0,1,dp);
}
//greedy
long getMaximumProfit(long *values, int n)
{
 //vector<vector<long>>dp(n,vector<long>(2,-1));
 
    //return sol(values,0,1,dp);
    long profit=0;
     for(int i=0;i<n-1;i++){
         if(values[i]<values[i+1])    profit+=values[i+1]-values[i];
     }
 return profit;
}
