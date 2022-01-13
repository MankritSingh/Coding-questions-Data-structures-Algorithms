/*
Question Link:https://atcoder.jp/contests/dp/tasks/dp_a
video link:https://www.youtube.com/watch?v=mnuBvHbMNJM

I have solved this question using iterative approach too.And it works really well

Analysis:We should try to see the independent problems that exist in the whole problem.For eg here we think that the cost to arrive at the final rock must be what?
we know that we can only arrive at final rock i from the rock i-1 and rock i-2.
Therefore this tells us one important thing that if we know the min cost to arrive at the rock i-1 and i-2 then its simple to know the min cost to arrive at 
rock i. Extending this logic we can say that min cost to reach rock i-1 is easliy calculated by knowing the cost of rock i-2 and rock-3.
now the cost of arriving at rock 0(starting rock) is 0.This is absolute and depends on nothiing else,therefore this also servers as our base condition.
also the cost of arriving at rock 1 and rock 2 is also only and only dependent on rock 0,therefore that can be calculated easily too.
This logic helped us solve this problem.
*/ 
#include<bits/stdc++.h>
using namespace std;
std::vector<int>v ;

#define ll long long int
int dp[10000000];

int func(int n){
    int cost=INT_MAX;
    if(n==0) return 0;
    if(dp[n]!= -1) return dp[n];
    cost=min(cost,func(n-1)+abs(v[n]-v[n-1]));
    if(n>1)
    cost=min(cost,func(n-2)+abs(v[n]-v[n-2]));
    return dp[n]=cost;
    
    // if(n==0) return 0;
    // if(dp[n]!=-1) return dp[n];
    // if(n>1)
    // return dp[n]=min(func(n-1)+abs(v[n]-v[n-1]),func(n-2)+abs(v[n]-v[n-2]));
}

int main()
{
    int n,ncopy;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    ncopy=n;
    while(ncopy--){
        int val;
        cin>>val;
        v.push_back(val);
    }
    
    cout<<func(n-1)<<endl;
}
