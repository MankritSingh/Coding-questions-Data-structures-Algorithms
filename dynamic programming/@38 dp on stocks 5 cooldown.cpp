/*Question:the same problem but with a constraint that there is a cooldown after selling
*/
//tabulation
#include <bits/stdc++.h> 
int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            if(j){
                int buy=-prices[i]+dp[i+1][0];
                int notbuy=dp[i+1][1];
                dp[i][j]=max(buy,notbuy);
                }else{
                int sell=INT_MIN;
                //if(i+2<=n){
                    sell=prices[i]+dp[i+2][1];
                //}    
                int dontsell=dp[i+1][0];
                dp[i][j]=max(sell,dontsell);
            }
        }
    }
    return dp[0][1];
}
//space optimized
#include <bits/stdc++.h> 
int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    vector<int>front2(n+2,0);
    vector<int>front1(n+2,0);
    vector<int>curr(n+2,0);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            if(j){
                int buy=-prices[i]+front1[0];
                int notbuy=front1[1];
                curr[j]=max(buy,notbuy);
                }else{
                int sell=INT_MIN;
                //if(i+2<=n){
                    sell=prices[i]+front2[1];
                //}    
                int dontsell=front1[0];
                curr[j]=max(sell,dontsell);
            }
        }
        front2=front1;
        front1=curr;
    }
    return curr[1];
}
