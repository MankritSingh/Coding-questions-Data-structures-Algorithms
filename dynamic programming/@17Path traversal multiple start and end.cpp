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
