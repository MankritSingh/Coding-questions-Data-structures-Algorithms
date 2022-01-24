#include <bits/stdc++.h>
using namespace std;
long long dp[110][100010];
int val[105],wt[105];

long long kp(int n,int wLeft){
    //base condition
    if(n<0 || wLeft==0) return 0;
    if(dp[n][wLeft]!=-1) return dp[n][wLeft];
    //what will we return when we dont select the current element
    long long ans= kp(n-1,wLeft);//w remains same
    //what we will return if we select the current element
    if(wLeft-wt[n]>=0)
       ans=max(ans,kp(n-1,wLeft-wt[n])+val[n]) ;
    return dp[n][wLeft]=ans;
    
}

int main() {
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
	   cin>>wt[i]>>val[i]; 
	}
	memset(dp,-1,sizeof(dp));
	cout<<kp(n-1,w);
	return 0;
}
