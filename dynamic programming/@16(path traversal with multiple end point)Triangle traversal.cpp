/*Question link:https://www.codingninjas.com/codestudio/problems/triangle_1229398
Question:we are given a triangle with values.We have to find a path from the top to the bottom.THe path cost is to be
minimized.This is different as compared to previous question as in this the end point can be any element of the last row.

Analysis:In this question the only change or difference is that we dont have a single end point but we can have any end endpoint
of the many given elements of the last row.So we solve the question in such a way that ,lets say we have only 1 element
then the least cost to reach it is the element itself.THe second row elements can be reached only by the first row single element.
The third row elements now have a choice.THe either they can be reached from row-1,col-1 or row-1,col.
*/

//iterative
#include<bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));
    dp[0][0]=triangle[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i+1;j++){
            int up=INT_MAX;
            int upleft=INT_MAX;
            if(j<i) up=dp[i-1][j];
            if(j>0)    upleft=dp[i-1][j-1];
            dp[i][j]=min(up,upleft);
            dp[i][j]+=triangle[i][j];
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[n-1][i]);
    }
    return ans;
}
//space optimization
#include<bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n){
    //vector<vector<int>>dp(n,vector<int>(n,-1));
    vector<int>dp(n,0);
    if (n==1) return triangle[0][0];
    dp[0]=triangle[0][0];
    for(int i=1;i<n;i++){
        vector<int>temp(n,0);
        for(int j=0;j<i+1;j++){
            int up=INT_MAX;
            int upleft=INT_MAX;
            if(j<i) up=dp[j];
            if(j>0)    upleft=dp[j-1];
            temp[j]=min(up,upleft);
            temp[j]+=triangle[i][j];
        }
        dp=temp;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[i]);
    }
    return ans;

}
//Recursive
#include<bits/stdc++.h>
int sol(int n,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    if(n==0) return triangle[0][0];
    if(dp[n][col]!=-1) return dp[n][col];
    int up=INT_MAX;
    int upleft=INT_MAX;
    if(col<n) up=triangle[n][col]+sol(n-1,col,triangle,dp);
    if(col>0)    upleft=triangle[n][col]+sol(n-1,col-1,triangle,dp);
    return dp[n][col]=min(up,upleft);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int ans=INT_MAX;
    for(int i=0;i<n;i++) ans=min(ans,sol(n-1,i,triangle,dp));
    return ans;
}
