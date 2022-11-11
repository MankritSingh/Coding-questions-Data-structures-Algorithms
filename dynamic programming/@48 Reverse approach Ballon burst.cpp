/*Question:We are given an array that has values of each ballon.When we burst a given ballon,we get the earning as prev ballons value*curr ballon*next ballon.
for any case where we dont have a ballon present,we can take the value as 1.Find the max that can be earned.

Analysis:THis problem appears to be quite similar to the previous problem but has a variation.
WHen we burst a ballon the value is dependent on the neighbours.
NOw usually we approach by selecting the first ballon we will burst and then solve the neighbouring problem as they are independent.
But in this case,the problems will not be independent
WHy?The reason is that the neighbouring values,will change accoridng the order of the bursting ballons,so how will we have a definite value without knowing the nieghbour
This is the reason that the problems are not independent.THIS IS ONE OF THE MOST iMPoRTANT POINT TO NOTE HERE>/
**NOW USUALLY WHEN WE HAVE SUCH PROBLEM<WE CHANGE THE DIRECTION OF APProACH
instead of seeing in the order that which ballon we had burst first,we will instead see in the order that which ballon was burst last.
WHat happens now is that when the ballon is alone,it will be independent.
In the next iteration we will check the partions to find the second last ballon burst.
NOw the nieghbours arent a[k-1] and a[k+1],instead they are a[i-1] and a[j+1].
This is how we are approach in a end to start manner.
*/

//memoization
#include <bits/stdc++.h> 
int sol(vector<int>&a,int i,int j,vector<vector<int>>&dp){
       if(i>j)    return 0;
       if(dp[i][j]!=-1)    return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
	//int earn=(a[i-1]*a[k]*a[j+1]) +sol(a,i,k-1,dp)+sol(a,k+1,j,dp); eariler using this,but it gives immediate neighbour and is appraoch of first ballon to last
        int earn=(a[i-1]*a[k]*a[j+1]) +sol(a,i,k-1,dp)+sol(a,k+1,j,dp);//this is approach of last to first works correctly
        ans=max(ans,earn);
    }
    return dp[i][j]=ans;
}
int maxCoins(vector<int>& a)
{
    a.insert(a.begin(),1);
    a.push_back(1);
    vector<vector<int>>dp(a.size(),vector<int>(a.size(),-1));
	return sol(a,1,a.size()-2,dp);
}
//iterative
int maxCoins(vector<int>& a)
{
    a.insert(a.begin(),1);
    a.push_back(1);
    vector<vector<int>>dp(a.size(),vector<int>(a.size(),0));
    for(int i=a.size()-2;i>=1;i--){
        for(int j=i;j<a.size()-1;j++){
            int ans=INT_MIN;
            for(int k=i;k<=j;k++){
                int cost=(a[i-1]*a[k]*a[j+1])+dp[i][k-1]+dp[k+1][j];
                ans=max(ans,cost);
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][a.size()-2];
}
