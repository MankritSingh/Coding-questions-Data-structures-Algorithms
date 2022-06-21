/*Question link:https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
Question:Minimum path through a matrix.We are given a matrix with various values.We have to find the minimum cost to reach
the right bottom end.We can only travel right and down.

Analysis:This question is quite similar to the prevoius question and is infact a variation of them.In such cases we 
think about the original solutions and make changes in them according to the requirements.
*/

//recursive/memoization
#include<bits/stdc++.h>
int s(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(r==0 && c==0) return grid[r][c];
    if(dp[r][c]!=-1) return dp[r][c];
    int left=INT_MAX,up=INT_MAX;
    if(r>0) left=s(r-1,c,grid,dp)+grid[r][c];
    if(c>0) up=s(r,c-1,grid,dp)+grid[r][c];
    return dp[r][c]=min(left,up);
}
int minSumPath(vector<vector<int>> &grid) {
    int r=grid.size();
    int c=grid[0].size();
    vector<vector<int>>dp(r,vector<int>(c,-1));
    return s(r-1,c-1,grid,dp);  
}

//iterative
int minSumPath(vector<vector<int>> &grid) {
    int r=grid.size();
    int c=grid[0].size();
    vector<vector<int>>dp(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 && j==0) dp[i][j]=grid[i][j];
            else{
                    int left=INT_MAX,up=INT_MAX;
                    if(i>0) left=dp[i-1][j]+grid[i][j];
                    if(j>0) up=dp[i][j-1]+grid[i][j];
                    dp[i][j]=min(left,up);
            }
        }
    }
    return dp[r-1][c-1];
}
//iterative with space  optimization O(n^2)->O(n)
int minSumPath(vector<vector<int>> &grid) {
    int r=grid.size();
    int c=grid[0].size();
//     vector<vector<int>>dp(r,vector<int>(c,-1));
//     return s(r-1,c-1,grid,dp);  
    vector<int>prev(c,0);
    for(int i=0;i<r;i++){
        vector<int>temp(c,0);
        for(int j=0;j<c;j++){
            if(i==0 && j==0) temp[j]=grid[i][j];
            else{
                    int left=INT_MAX,up=INT_MAX;
                    if(j>0) left=temp[j-1]+grid[i][j];
                    if(i>0) up=prev[j]+grid[i][j];
                    temp[j]=min(left,up);
            }
        }
        prev=temp;
    }
    return prev[c-1];
}
