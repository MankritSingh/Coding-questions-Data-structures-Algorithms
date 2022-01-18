/*
Question link:https://atcoder.jp/contests/dp/tasks/dp_c
Question: we are given a multidimesional array where each line represents a score.now we have a condition that when we select the next element from the next row
the element cannot be from the same row ie if we select a0 from a0 a1 a2 then in the next row b0 b1 b2 we can only select b1 or b2.
We have to maximize the score.

Analysis:The approach we use here has been developed from the prevoius questions.let the final values be a0 a1 a2.
lets assume that the final answer includes a0,then the prevoius value will be either from row 1 or row 2.Now if we have the max score of 
those values we get the answer.now we do the same for a1 and a2.
So now as the recursion goes back till the first row ie row=0,the score is simply the value itself.This is our base condition.
*/

#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define pb push_back
#define w(x) int x;cin>>x;while(x--) //while loop to take input and run for x
#define f(x) int x;cin>>x;for(int i=0;i<x;i++)//for loop to take input and run for x
#define inpv(vector) int x;cin>>x;for(int i=0;i<x;i++){int val;cin>>val;vector.pb(val);}
#define printv(x) for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}//print vector
using namespace std;

//-----------------------------------------------------------------------  
//static int dp[10010][10010];
vector<vector<int>>dp;//using a vector of vector ie mulidimensional dp here as the size is too big for static alloacation.There either we have to use vector 
//or allocate memory dynamically to array.


long long func(vector<vector<int>>&v,int n,int m){
    if(dp[n][m]!=0) return dp[n][m];
    long long maxval=0;
    if(n==0) return v[n][m];
    for(int k=0;k<3;k++){
        if(k!=m)
            maxval=max(maxval,func(v,n-1,k));
    }
    return dp[n][m]=v[n][m]+maxval;
} 
int main() {
    for(int i=0;i<100010;i++)//allocating memory dynamcically for dp array as its size is big.
        dp.pb({0,0,0});
    long long ans=0;
    vector<vector<int>>v;
    w(x){
        vector<int>temp;
        for(int i=0;i<3;i++){
            
            int val;
            cin>>val;
            temp.pb(val);
        }
        v.pb(temp);
        temp.clear();
    }
    for(int i=0;i<3;i++){
        ans=max(ans,func(v,v.size()-1,i));
    }
    cout<<ans;
	return 0;
}
