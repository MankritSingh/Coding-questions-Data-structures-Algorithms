/*
Question Link:https://atcoder.jp/contests/dp/tasks/dp_a

Analysis:This question is same as that as frog 1 but now the user defines the number of jumps we can do.let the number of jumps we can do be k.
We to know the min cost to reach final stone i,we need to know to know the cost of stone i-1,stone i-2,...,stone i-k.
we can use a for loop to solve this problem.
This question also helps us relieze that if we have a complex problem,then we can try to solve the simpler varient of that problem and then improvize that
solution to solve the complex problem.Ofcourse this doesnt work for all problems.
*/
 
#include<bits/stdc++.h>
using namespace std;
std::vector<int>v ;

#define ll long long int
int dp[10000000];

int func(int n,int k){
    int cost=INT_MAX;
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n]; 
    for(int i=n-1;i>=n-k;i--)
    {
        if(i<0) break;
        cost=min(cost,func(i,k)+abs(v[n]-v[i]));
    }
    return dp[n]=cost;
}

int main()
{
    int n,ncopy,k;
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    ncopy=n;
    while(ncopy--){
        int val;
        cin>>val;
        v.push_back(val);
    }
    
    cout<<func(n-1,k)<<endl;
}
