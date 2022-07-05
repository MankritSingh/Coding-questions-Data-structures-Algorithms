/*Question:The same knapsack problem,but in this case it is unbounded ie we can take a given value any number of times.
Analysis:The question is solved in a similar way,the change here is that we can take a value multiple times.Therefore we will solve this in a similar manner in which
we solved the last 3 problems
*/
//Iterative
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i=0;i<w+1;i++){
       if(weight[0]<=i)    dp[0][i]=profit[0]*(i/weight[0]); 
    }  
    for(int i=1;i<n;i++){
        for(int j=0;j<w+1;j++){
            int notTake=dp[i-1][j];
            int take=0;
            if(weight[i]<=j)    take=profit[i]+dp[i][j-weight[i]];
            dp[i][j]=max(take,notTake);
        }
    }
    return dp[n-1][w];
}
//space optimized
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int>dp(w+1,0);
    for(int i=0;i<w+1;i++){
       if(weight[0]<=i)    dp[i]=profit[0]*(i/weight[0]); 
    }  
    for(int i=1;i<n;i++){
        for(int j=0;j<w+1;j++){
            int notTake=dp[j];
            int take=0;
            if(weight[i]<=j)    take=profit[i]+dp[j-weight[i]];
            dp[j]=max(take,notTake);
        }
    }
    return dp[w];
}
//Recursive
int sol(int n, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
        if(n==0){
            if(weight[0]<=w)    return profit[0]*(w/weight[0]);
            else return 0;
        }
    if(dp[n][w]!=-1) return dp[n][w];
            int notTake=sol(n-1,w,profit,weight,dp);
            int take=0;
            if(weight[n]<=w)    take=profit[n]+sol(n,w-weight[n],profit,weight,dp);
            return dp[n][w]=max(take,notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return sol(n-1,w,profit,weight,dp);
}
