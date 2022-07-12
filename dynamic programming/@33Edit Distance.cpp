/*Question:It is a famous question in which we are given two strings and we have to make the strings identical.We are given 3 operations.
Replace char,delete char and insert char. Find the min no of steps required

Analysis:THis question is quite similar to the previous question we have done,where we had to match two strings and the operations given are replace and delete.
In this question now we have a new option of replace.THere is no change in the answer,only one more call for the replace is added to the previous code.
*/
//Recursion
int sol(string &str1, string &str2,int n,int m,vector<vector<int>>&dp){
    if(n<0)    return m+1;
    if(m<0)    return n+1;
    if(dp[n][m]!=-1)    return dp[n][m];
    if(str1[n]==str2[m])    return dp[n][m]=sol(str1,str2,n-1,m-1,dp);
    int insert=1+sol(str1,str2,n,m-1,dp);
    int del=1+sol(str1,str2,n-1,m,dp);
    int replace=1+sol(str1,str2,n-1,m-1,dp);
    return dp[n][m]=min(insert,min(del,replace));
}
int editDistance(string str1, string str2)
{
    int n=str1.length(),m=str2.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return sol(str1,str2,n-1,m-1,dp);
}
//tabulation
int editDistance(string str1, string str2)
{
    int n=str1.length(),m=str2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0)    dp[i][j]=j;
            else if(j==0)    dp[i][j]=i;
            else if(str1[i-1]==str2[j-1])    dp[i][j]=dp[i-1][j-1];
            else{
                int insert=1+dp[i][j-1];
                int del=1+dp[i-1][j];
                int replace=1+dp[i-1][j-1];
                dp[i][j]=min(min(insert,del),replace);
            }
        }
    }
    return dp[n][m];
}
//Space optimization We can optimize it to single array as we require both i-1 and j-1.If we want we can store the prev value in temp variable and use a single array
int editDistance(string str1, string str2)
{
    int n=str1.length(),m=str2.length();
    vector<int>prev(m+1,0);
     vector<int>curr(m+1,0);
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0)    curr[j]=j;
            else if(j==0)    curr[j]=i;
            else if(str1[i-1]==str2[j-1])    curr[j]=prev[j-1];
            else{
                int insert=1+curr[j-1];
                int del=1+prev[j];
                int replace=1+prev[j-1];
                curr[j]=min(min(insert,del),replace);
            }
        }
        prev=curr;
    }
    return prev[m];
}
