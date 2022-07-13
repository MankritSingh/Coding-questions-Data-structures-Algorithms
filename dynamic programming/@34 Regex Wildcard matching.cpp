/*Question:https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650
Question:Given two string,we have to see if they match or not.The text string is a string consisting only of lowercase characters whereas the patterns string has
lowercase,? and *. ? means a single character and * means 0 or more characters.

Analysis:Just by looking at the question we understand that the the general character matching is something we have done before so its no issue.The ? also is simple 
and can be easily handled.The main issue is with the *.The * is handled so that we consider all cases for it ie * is 0 to * is the whole remaining string and everything
in between.This is handled in two ways.
*/
//recursion
#include<vector>
bool sol(string &pattern, string &text,int n,int m,vector<vector<int>>&dp){
    if(n<0 && m<0)    return true;
    if(n<0)    return false;
    if(m<0){
        for(int i=n;i>=0;i--){
            if(pattern[i]!='*')    return false;
        }
        return true;
    }
    if(pattern[n]!='?' && pattern[n]!='*' && pattern[n]!=text[m])    return false;
    if(dp[n][m]!=-1)    return dp[n][m];
    if(pattern[n]==text[m] || pattern[n]=='?')    return dp[n][m]=sol(pattern,text,n-1,m-1,dp);
    //way 1 of handling *
    bool ans=sol(pattern,text,n-1,m,dp);
    for(int i=0;i<=m+1;i++){
      bool temp=sol(pattern,text,n-1,m-i,dp);
        ans=ans||temp;
    }
    //way 2 of handling star
    //return sol(pattern,text,n-1,m) | sol(pattern,text,n,m-1);
    return dp[n][m]=ans;
}
bool wildcardMatching(string pattern, string text)
{
   
    int n=pattern.length();
    int m=text.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return sol(pattern,text,n-1,m-1,dp);
}
//Tabulation
bool wildcardMatching(string pattern, string text)
{
   
    int n=pattern.length();
    int m=text.length();
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    //return sol(pattern,text,n-1,m-1,dp);
    dp[0][0]=true;
    for(int i=1;i<n+1;i++){
        bool flag=true;
       for(int ind=1;ind<=i;ind++){
           if(pattern[ind-1]!='*'){
               flag=false;
               break;
           }    
       }
        dp[i][0]=flag;
    }
    for(int i=0;i<n+1;i++){
        for(int j=1;j<m+1;j++){
           if(i==0)    dp[0][j]=false;
            if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')    dp[i][j]=dp[i-1][j-1];
            else if(pattern[i-1]=='*')    dp[i][j]=dp[i-1][j] | dp[i][j-1];
            else dp[i][j]=false;
        }
    }
    return dp[n][m];
}
//Space optimized
bool wildcardMatching(string pattern, string text)
{
   
    int n=pattern.length();
    int m=text.length();
    //vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
    //return sol(pattern,text,n-1,m-1,dp);
    vector<bool>prev(m+1,false);
    vector<bool>curr(m+1,false);
    prev[0]=true;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(j==0){
                bool flag=true;
                for(int ind=1;ind<=i;ind++){
                   if(pattern[ind-1]!='*'){
                   flag=false;
                   break;
                   }    
               }
                curr[0]=flag;
            }
            else if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')    curr[j]=prev[j-1];
            else if(pattern[i-1]=='*')    curr[j]=prev[j] | curr[j-1];
            else curr[j]=false;
        }
        prev=curr;
    }
    return prev[m];
}
