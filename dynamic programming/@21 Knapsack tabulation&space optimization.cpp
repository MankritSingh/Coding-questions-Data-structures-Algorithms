/*the knapsack recursion solution and explanation is written previously.Now we will look at the tabulation way and space optimzation */
video:https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20&ab_channel=takeUforward
//tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    int t=value.size();
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    for(int i=weight[0];i<maxWeight+1;i++)    dp[0][i]=value[0];
    for(int i=1;i<t;i++){
        for(int j=0;j<maxWeight+1;j++){
            int nottake=dp[i-1][j];
            int take=INT_MIN;
            if(weight[i]<=j)    take=value[i]+dp[i-1][j-weight[i]];
            dp[i][j]=max(take,nottake);
        }
    }
    return dp[t-1][maxWeight];
}

/*Space optimization:IN space optimization,we were previously using 2 rows but we can do it simply using a single array.
When we observe the code we see the previous array is being used twice,first in nottaken that is we see the value just above us.Now this is no issue as
it is the same as seeing ourselves.The second place we use the previous array is when we see take which lies on the left side of the prevoius array.
Now this is an issue as we have already updated the previous array blocks when we use a single array.
Therefore the first thing that comes to our mind is,why dont we update the array from left.But the dp array is filled from left to right as the updated info
ie the info found previously is used to update the current value.But as we see in our code,The values we need to use are the one we have already found and are stored
in the previous array.THEREFORE we update the array from right to left.
*/
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    int t=value.size();
    //vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    vector<int>dp(maxWeight+1,0);
    for(int i=weight[0];i<maxWeight+1;i++)    dp[i]=value[0];
    for(int i=1;i<t;i++){
        for(int j=maxWeight;j>=0;j--){
            int nottake=dp[j];
            int take=INT_MIN;
            if(weight[i]<=j)    take=value[i]+dp[j-weight[i]];
            dp[j]=max(take,nottake);
        }
    }
    return dp[maxWeight];
}
