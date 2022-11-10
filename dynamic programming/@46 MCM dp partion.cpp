/*Question:We are given the dimesions of matrices that are supposed to be multiplied together.Now we have to find the minimum number of steps that
will be required to compute the answer. As we know that the number of steps requied to multiply two matrix of r1*c1 and r2*c2 is r1*c1*c2 where r2=c1.

Analysis:This is solved using Dp partion.Here we have to form partitions of the given order of multiplication and find whats the best way.

*/
//recursive
#include <bits/stdc++.h> 
int sol(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
    if(i==j)    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=(arr[i-1]*arr[k]*arr[j])+
            sol(arr,i,k,dp)+sol(arr,k+1,j,dp);
        ans=min(ans,steps);
    }
    return dp[i][j]=ans;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return sol(arr,1,N-1,dp);
}
//iterative
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            if(i==j)    {dp[i][j]=0;}
            else{
                int ans=INT_MAX;
                for(int k=j-1;k>=i;k--){
                    int steps=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                    ans=min(ans,steps);
                    }
                    dp[i][j]=ans;
            }
        }
    }
    return dp[1][N-1];
}
