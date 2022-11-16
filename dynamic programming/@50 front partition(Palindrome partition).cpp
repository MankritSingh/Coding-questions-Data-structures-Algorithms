/*Question:We are given a string and we have to find the minimum number of partitions that the string can be split up into,so each partion is palindrome.
IF there is no need to partition then we should avoid it.

Analysis:The following question is simple but requires a slight change is solving.
When we look at the question,we realize that we have to split up the string into partitions,just like all the prevoius questions,
but one thing we understand is that we cannot make a partition if the split up partition is not a palindrome.
SO now FRONT partition works as follows 
1)we start from i=0 to i=n,where we split the string into partitions,the first string is only checked and not both as we go in a linear way.
2)WE know that for each single character we can surely split the string ie size 1, we want the min value so we will check all values for k=1 to n
*/
//recursive + memiozation

#include <bits/stdc++.h>
bool ispal(string str,int i,int j){
    while(i<j)  if(str[i++]!=str[j--])    return false;
    return true;
}
int sol(string &str,int i,int n,vector<int>&dp){
    //if(!ispal(str,i,j))    return 101;
    if(i==n)    return 0;
    if(dp[i]!=-1)    return dp[i];
    int ans=INT_MAX;
    for(int k=i;k<n;k++){
        int temp=101;
        if(ispal(str,i,k))    temp=1+sol(str,k+1,n,dp);
        ans=min(ans,temp);
    }
    return dp[i]=ans;
}
int palindromePartitioning(string str) {
  vector<int>dp(str.length(),-1);
  return sol(str,0,str.length(),dp)-1;
}

//tabulation
#include <bits/stdc++.h>
bool ispal(string str,int i,int j){
    while(i<j)  if(str[i++]!=str[j--])    return false;
    return true;
}
int palindromePartitioning(string str) {
    int n=str.length();
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int ans=INT_MAX;
        for(int k=i;k<n;k++){
            int temp=101;
            if(ispal(str,i,k))    temp=1+dp[k+1];
            ans=min(ans,temp);
        }
        dp[i]=ans;
    }
    return dp[0]-1;
}
