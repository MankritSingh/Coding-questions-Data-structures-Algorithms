/*Question:https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0
Analysis:The question appears to be simple and is similar to the previous questions but an important difference
here is that,When we are making a choice we have 2 options,to take,or to not take.But this is not really the case.
As the question says,we have unlimited supply of coins,therefore we can select 1 coin,2 coin,and so on.
Now we may think that lets take the most amount of coins possible as it will decrease the denominations but that 
is not the case.As we see sometimes we dont need to take the max possible coins of a given denomination,
we can instead take a few coins less,THis will now help decrease the amount of coins used in future.
SO how do we solve this issue?We can think that for a given coin,we can run a for loop,but the better way of
doing this is to take a single coin and keep the index same.WHat this will do is that we will take coin 1 by one
and remain at the same index.SO we can try all the possible sequences.
SO the most IMPORTANT thing to learn from this question is that sometimes we only change on index/parameter
of our given dp.

*/
//recursion
#include<algorithm>
int sol(int n,vector<int> &num, int x,vector<vector<int>>&dp){
    if(n==0){
        if(x%num[0]==0)    return x/num[0];
        else return 1e5;
    }
    if(dp[n][x]!=-1)    return dp[n][x];
    int notTake=sol(n-1,num,x,dp);
    int take=1e5;
    if(num[n]<=x)    take=1+sol(n,num,x-num[n],dp);
    return dp[n][x]=min(take,notTake);
}
int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>>dp(num.size(),vector<int>(x+1,-1));
    int ans=sol(num.size()-1,num,x,dp);
    if(ans>x)    return -1;
    else    return ans;
}
//iterative
int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>>dp(num.size(),vector<int>(x+1,0));
    //sort(num.begin(),num.end());
//     int ans=sol(num.size()-1,num,x,dp);
//     if(ans>x)    return -1;
//     else    return ans;
    for(int i=0;i<x+1;i++){
        if(i%num[0]==0)    dp[0][i]=i/num[0];
        else dp[0][i]=1e5;
    }
    for(int i=1;i<num.size();i++){
        for(int j=0;j<x+1;j++){
              int notTake=dp[i-1][j];
              int take=1e5;
              if(num[i]<=j)    take=1+dp[i][j-num[i]];
              dp[i][j]=min(take,notTake); 
        }
    }
    int ans= dp[num.size()-1][x];
    if(ans>=1e5)    return -1;
    else return ans;
    
}
//space optimized
int minimumElements(vector<int> &num, int x)
{
    vector<int>dp(x+1,0);
    //sort(num.begin(),num.end());
//     int ans=sol(num.size()-1,num,x,dp);
//     if(ans>x)    return -1;
//     else    return ans;
    for(int i=0;i<x+1;i++){
        if(i%num[0]==0)    dp[i]=i/num[0];
        else dp[i]=1e5;
    }
    for(int i=1;i<num.size();i++){
        for(int j=0;j<x+1;j++){
              int notTake=dp[j];
              int take=1e5;
              if(num[i]<=j)    take=1+dp[j-num[i]];
              dp[j]=min(take,notTake); 
        }
    }
    int ans= dp[x];
    if(ans>=1e5)    return -1;
    else return ans;
    
}
