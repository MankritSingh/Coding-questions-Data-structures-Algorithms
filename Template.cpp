//the template i use for c++ coding
#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define pb push_back
#define w(x) int x;cin>>x;while(x--) //while loop to take input and run for x
#define f(x) int x;cin>>x;for(int i=0;i<x;i++)//for loop to take input and run for x
#define inpv(vector) int x;cin>>x;for(int i=0;i<x;i++){int val;cin>>val;vector.pb(val);}//take input
//for the vector passed.The len of vector is taken from user.
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
  
  
int main() {

	return 0;
}
