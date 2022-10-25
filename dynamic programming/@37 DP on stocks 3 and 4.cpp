/*Question:Same question as prevoius but we have a limit on number of transactions,we just add a simple 
but in this case we cant get the question passed using recurssion so we have to use tabulation

*/
#include <bits/stdc++.h> 
// int len;
// int sol(vector<int> &prices,int n,int k,int canBuy,vector<vector<vector<int>>>&dp){
//     if(k==0)    return 0;
//     if(n==len)    return 0;
// //     if(dp[n][k][canBuy]!=-1)   return dp[n][k][canBuy];
//     int profit=0;
//     if(canBuy){
//         int buys=-prices[n]+sol(prices,n+1,k,0,dp);
//         int notbuy=sol(prices,n+1,k,1,dp);
//         profit=max(buys,notbuy);
//     }
//     else{
//         int sells=prices[n]+sol(prices,n+1,k-1,1,dp);
//         int notsells=sol(prices,n+1,k,0,dp);
//         profit=max(sells,notsells);
//     }
//     return dp[n][k][canBuy]=profit;
//     return profit;
// }
int maximumProfit(vector<int> &prices, int n, int k)
{
//     len=n;
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(k,vector<int>(2,-1)));
    
//     return sol(prices,0,k,1,dp);
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int z=1;z<=k;z++){
                    if(j){
                        int buy=-prices[i]+dp[i+1][0][z];
                        int notbuy=dp[i+1][1][z];
                        dp[i][j][z]=max(buy,notbuy);
                    }else{
                        int sell=prices[i]+dp[i+1][1][z-1];
                        int notsell=dp[i+1][0][z];
                        dp[i][j][z]=max(sell,notsell);
                    }
                }
            }
        }
    return dp[0][1][k];
}

//space optimized
int maximumProfit(vector<int> &prices, int n, int k)
{
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
       vector<vector<int>>next(2,vector<int>(k+1,0));
       vector<vector<int>>curr(2,vector<int>(k+1,0));
    for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int z=1;z<=k;z++){
                    if(j){
                        int buy=-prices[i]+next[0][z];
                        int notbuy=next[1][z];
                        curr[j][z]=max(buy,notbuy);
                        
                    }else{
                        int sell=prices[i]+next[1][z-1];
                        int notsell=next[0][z];
                        curr[j][z]=max(sell,notsell);
                    }
                }
            }
        next=curr;
        }
    return curr[1][k];
}
