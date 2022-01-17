/*
Question:find the length of the longest increasing sub sequence.

Analysis:This question is a little different from the previous questions.In this question the approach we use it that
we start from the right most element of the array.We say that let the longest sequence have this element as its last element.
Then we look at all the elements that are less than the selected element to find all the possible sequences.
Without dp the func functions time complexity would be O(n^2) but with dp it comes down to O(n).
*/

#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define pb push_back
#define w(x) int x;cin>>x;while(x--) //while loop to take input and run for x
#define f(x) int x;cin>>x;for(int i=0;i<x;i++)//for loop to take input and run for x
#define inpv(vector) int x;cin>>x;for(int i=0;i<x;i++){int val;cin>>val;vector.pb(val);}//take input
//for the vector passed.The len of vector is taken from user
#define printv(x) for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}//print vector
using namespace std;
inline void inp( int &n ) //use only for 10^9 size
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }
  
int dp[10000010]; 
//-------------------------------------------------------------------------------------------------//
  
int func(vector<int>&v,int n){
    int answer=1;
    if(dp[n]!=0) return dp[n];
    for(int i=1;i<=n;i++)
    {
        if(v[n]>v[n-i]){
            answer=max(answer,func(v,n-i)+1);
        }
    }
    return dp[n]=answer;
}
  
int main() {
    vector<int>v;
    inpv(v);
    int ans=1;
    for(int i=v.size()-1;i>=0;i--){
        ans=max(ans,func(v,i));
    }
    cout<<ans<<endl;
    // cout<<func(v,v.size()-v.size()+3);
	return 0;
}
