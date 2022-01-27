#include <bits/stdc++.h>
using namespace std;

string ss,tt,answer="";
int dp[1010][1010];
int func(int s,int t){
    if(s==-1 || t==-1) return 0;
    if(dp[s][t]!=-1) return dp[s][t];
    if(ss[s]==tt[t]){
        answer+=ss[s];
     return dp[s][t]=1+func(s-1,t-1);   
    } 
    else{
        int ans=func(s-1,t);
        ans=max(ans,func(s,t-1));
        return dp[s][t]=ans;
    }
}

int main() {
	cin>>ss>>tt;
    int s=ss.length();
    int t=tt.length();
    memset(dp,-1,sizeof(dp));
    int len=func(s-1,t-1);
    // reverse(answer.begin(),answer.end());
    // cout<<"Length of Longest Common Subsequence:"<<len<<endl<<"Longest Subsequence:"<<answer;
    cout<<len;
	return 0;
}
