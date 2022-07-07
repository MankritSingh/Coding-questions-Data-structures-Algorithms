/* Question:It is a famous dp question,where we are given a rod and we have to cut the rod into any number of pieces to achieve max profit.For each length ranging 
from 1 to n,we given an array that tells the price of the matching value.Eg we will earn 2 for rod length 1,4 for rod length 2 and so on.One thing to note is that
the indexing is 1 based.

Analysis:Consider a rod of length of 5.Now it case where we have kind of infinte supply and limited supply.We can keep the rod uncut and get the price of length 5
or we can cut the rod into 5 pieces of length 1. Another important thing is the indexing.We have to take care of the indexing as it is 1 based indexing.

*/
//recursive
int sol(int ind,int rod,vector<int> &price,vector<vector<int>>&dp){
    if(ind==0)    return 0;
    if(dp[ind][rod]!=-1)    return dp[ind][rod];
    int notTake=sol(ind-1,rod,price,dp);
    int take=0;
    if(ind<=rod)    take=price[ind-1]+sol(ind,rod-ind,price,dp);
    return dp[ind][rod]=max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return sol(n,n,price,dp);
}

//iterative
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int i=0;i<n+1;i++)    dp[0][1]=0;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            int notTake=dp[i-1][j];
            int take=0;
            if(i<=j)    take=price[i-1]+dp[i][j-i];
            dp[i][j]=max(take,notTake);
        }
    }
    return dp[n][n];
}
//space optimized
int cutRod(vector<int> &price, int n)
{
    vector<int>prev(n+1,0);
    vector<int>curr(n+1,0);
    for(int i=0;i<n+1;i++)    prev[i]=0;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            int notTake=prev[j];
            int take=0;
            if(i<=j)    take=price[i-1]+curr[j-i];
            curr[j]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[n];
}
