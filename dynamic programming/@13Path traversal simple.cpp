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

//recursive solution
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

//iterative solution
/*We think what will be the answer if there is only 1 row or only 1 column? for both the cases no matter what the other 
field is answer is always 1 therefore we fill all row and col 1 with 1.And for arr[i][j] we get the answer by adding
the number of ways in the above row and the numbero of ways in left column*/

#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	int arr[m+1][n+1]={0};
    for(int i=1;i<m+1;i++) arr[i][1]=1;
    for(int i=1;i<n+1;i++) arr[1][i]=1;
    for(int i=2;i<m+1;i++){
        for(int j=2;j<n+1;j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    return arr[m][n];
}

//Space optimization:In this case we observe that we only need the prevoiys row to find the next element of current row
//therefore we can reeduce the space complexity to O(n)from O(n^2)
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    int prev[n]={0};
    for(int i=0;i<m;i++){
         int temp[n]={0};
        for(int j=0;j<n;j++){
            if(j==0) temp[j]=1;
            else temp[j]=prev[j]+temp[j-1];
        }
        copy(temp,temp+n,prev);
    }
    return prev[n-1];
}
