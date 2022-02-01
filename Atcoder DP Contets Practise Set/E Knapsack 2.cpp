/*
Question:knapsack 2 is the same knapsack problem but here the constraints change the way our problem is solved.The constriant on weight allows upto 10^9 therefore
we cannot use weight as a state as we will get TLE.
Analysis:As the constraint restrict us to solve this problem the usual way,we have to solve this problem by taking different state in dp
The most IMPORTANT thing here to understand how we can use the constraints to our advantage and solve some problems in a different way.
Another Important thing to note is that the dimension of DP usually shows us the upper bound of time complexity.Eg if dp is of size 10^5 then to fill dp we can do
max 10^5 calculations.Therefore we dont require more time than the time required to fill the dp.
In this question we say that the max value/profit from the constraints is 10^5 therefore we say that we will see for each value from 10^5 to 0,what is the lowest
weight we require to get that EXACT profit.THe profit should be exact.If we are not able to build that exact profit then we will store a big value in
so the answer becomes invalid because of weight limit.Now we traverse from 10^5 to 0 and the first answer that fullfils the weight limit is our answer.
*/

#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define pb push_back
#define w(x) int x;cin>>x;while(x--) //while loop to take input and run for x
#define f(x) int x;cin>>x;for(int i=0;i<x;i++)//for loop to take input and run for x
#define inpv(vector) int x;cin>>x;for(int i=0;i<x;i++){int val;cin>>val;vector.pb(val);}
#define printv(x) for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}//print vector
using namespace std;

//--------------------------------------------------------------------------------------------//  
long long dp[110][100010];
vector<int>val;
vector<int>wt;


long long func(int index,int val_left){
    if(val_left==0) return 0;
    if(index<0) return 1e12;
    if(dp[index][val_left]!=-1) return dp[index][val_left];
    
    long long ans=func(index-1,val_left);
    if(val_left-val[index]>=0)
    ans=min(ans,func(index-1,val_left-val[index])+wt[index]);
    return dp[index][val_left]=ans;
}


int main() {
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++){
        int val1,val2;
        cin>>val1>>val2;
        wt.pb(val1);
        val.pb(val2);
    }
    memset(dp,-1,sizeof(dp));
    int maxval=1e5;
    for(int i=maxval;i>=0;i--){
        long long answer=func(n-1,i);
        if(answer<=w){
            cout<<i;
            break;
        }
        
    }
	return 0;
}
