/*Question:We have to make a given string palindrome with min number of moves.

Analysis:We keep one pointer at start and one pointer at end.NOw we see if they match.If yes then just move both the pointer.If not,now we can either add the the character on 
the left or the character on the right.Also we need to add to min of those two.
*/
#include<vector>
int sol(int l,int r,string str,vector<vector<int>>&dp){
    if(l>=r)    return 0;
    if(dp[l][r]!=-1)    return dp[l][r];
    if(str[l]==str[r])    return 0+sol(l+1,r-1,str,dp);
    return dp[l][r]=1+min(sol(l+1,r,str,dp),sol(l,r-1,str,dp));
}
int minInsertion(string &str)
{
   
   int len=str.length();    
  vector<vector<int>>dp(len,vector<int>(len,0));
  return sol(0,len-1,str,dp);
}
