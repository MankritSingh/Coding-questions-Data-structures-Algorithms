/*Question:Given an array we have to find the longest increasing(not equal only increasing) subsequence.
Analysis:The question is similar to older questions(General DP questions).The important change or difference is that when we choose an element
we need to know the prevoius taken element,so now our dp indexes are dp[n][prev element].Where prev stores the index of previous element.
Now when we start,we have no previous element we will have -1. Now we can store negative element in the array so that causes an issue.
To solve this problem,we will store all values of prevElement as a n+1.

*/
#include<vector>
int sol(int arr[],int n,int prev,vector<vector<int>>&dp){
    if(n<0)    return 0;
    if(dp[n][prev+1]!=-1)    return dp[n][prev+1];
    int take=0;
    if(prev==-1 || arr[prev]>arr[n])    take=1+sol(arr,n-1,n,dp);
    int nottake=sol(arr,n-1,prev,dp);
    return dp[n][prev+1]=max(take,nottake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return sol(arr,n-1,-1,dp);
    
}
