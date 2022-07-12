/*Question:https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256
Question:Given 2 strings,We have to find the number of times string 2 occurs in string 1.

Analysis:This question is of string matching but the approach is same as that of previous question.We are going to use the same appraoch that
we used in counting number of ways we can generate a sum K question.
If the character matches,we have 2 choices,WE take the char or leave the char
If the char does not match,we have a single choice of not taking the char
*/
//Recursive
#include<bits/stdc++.h>
int mod = 1e9+7;
int sol(string &n, string &m, int i, int j,vector<vector<int>>&dp){
    if(j<0)    return 1;
    if(i<0)    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    if(n[i]==m[j]){
        return dp[i][j]=(sol(n,m,i-1,j-1,dp)+sol(n,m,i-1,j,dp))%mod;
    }
    else return dp[i][j]=sol(n,m,i-1,j,dp)%mod;
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>>dp(lt+1,vector<int>(ls+1,-1));
    return sol(t,s,lt-1,ls-1,dp);
}

//Tabulation
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>>dp(lt+1,vector<int>(ls+1,0));
    //return sol(t,s,lt-1,ls-1,dp);
    for(int i=0;i<lt+1;i++)    dp[i][0]=1;
    for(int i=1;i<lt+1;i++){
        for(int j=1;j<ls+1;j++){
            if(t[i-1]==s[j-1]){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
            else dp[i][j]=(dp[i-1][j]);
        }
    }
    return dp[lt][ls];
    
} 
//Single array space optimization
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    //vector<vector<int>>dp(lt+1,vector<int>(ls+1,0));
    //return sol(t,s,lt-1,ls-1,dp);
    vector<int>dp(ls+1,0);
    dp[0]=1;
    for(int i=1;i<lt+1;i++){
        for(int j=ls;j>=0;j--){
            if(t[i-1]==s[j-1]){
                dp[j]=(dp[j-1]+dp[j])%mod;
            }
            else dp[j]=(dp[j]);
        }
    }
    return dp[ls];
    
} 
