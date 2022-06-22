/*Question:https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998
question:We are given a matrix of NxM. We have to travel from the first row to the last row.THe starting and path can be
any of the element of the row.

Analysis:We will use the logic we have used prevoiusly to solve this question.We will tabulate the max path possible for each
element and then take the max of the last row.
*/
//iterative
#include<bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0) dp[i][j]=matrix[i][j];
            else{
                int left=INT_MIN,right=INT_MIN;
                int up=matrix[i][j]+dp[i-1][j];
                if(j>0)    left=matrix[i][j]+dp[i-1][j-1];
                if(j<m-1)    right=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=max(max(up,left),right);
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<m;i++){
        ans=max(ans,dp[n-1][i]);
    }
    return ans;
}
//space optimazatin
#include<bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    //vector<vector<int>>dp(n,vector<int>(m,-1));
    vector<int>dp(m,0);
    for(int i=0;i<n;i++){
         vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            if(i==0) //dp[i][j]=matrix[i][j];
                temp[j]=matrix[i][j];
            else{
                int left=INT_MIN,right=INT_MIN;
                int up=matrix[i][j]+dp[j];
                if(j>0)    left=matrix[i][j]+dp[j-1];
                if(j<m-1)    right=matrix[i][j]+dp[j+1];
               temp[j]=max(max(up,left),right);
                
            }
        }
        dp=temp;
    }
    int ans=INT_MIN;
    for(int i=0;i<m;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
}
//recursive
#include<bits/stdc++.h>
int sol(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(j<0 || j>=matrix[0].size()) return -1e6;//we use -1e6 instead of int min to avoid integer overflow
    if(i==0)    return matrix[0][j];
    if(dp[i][j]!=-1)    return dp[i][j];
     int up=matrix[i][j]+sol(i-1,j,matrix,dp);
     int left=matrix[i][j]+sol(i-1,j-1,matrix,dp);
     int right=matrix[i][j]+sol(i-1,j+1,matrix,dp);
     return dp[i][j]=max(up,max(left,right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans=INT_MIN;
    for(int i=0;i<m;i++){
        ans=max(ans,sol(n-1,i,matrix,dp));
    }
    return ans;
}
