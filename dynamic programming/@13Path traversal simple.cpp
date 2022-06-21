/*Question link:https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
Question:Imagine a MxN matrix.we are at the starting point that is 0,0 .We have to reach the bottom right point.
The only moves allowed is either down or right.Find the total number of unique ways

Analysis:When we first look at the question,the thing that comes to our brain is how will we identify the unique steps?
first we think about how we would solve the problems in general without thinking about programming.
Then we try to think how we can convert this logic to computer logic.

Solution:We observe that as we have only 2 ways ways of travelling ie right and down,then if we reach the right most or down
most point,then we will have only 1 option avaialble that is going directly to end point by going right or down.
Therefore we will return 1 when we are at either extreme and otherwise return travel right+travel down.
*/
#include <bits/stdc++.h> 
int s(int m,int n,vector<vector<int>>&dp){
    if(m==1 || n==1)    return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    return dp[m][n]=s(m-1,n,dp)+s(m,n-1,dp);
}


int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return s(m,n,dp);
}
