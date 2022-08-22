//https://codeforces.com/problemset/problem/1294/C

#include <bits/stdc++.h>
#define ll long long

#define pb push_back
#define w(x) int x;cin>>x;while(x--) //while loop to take input and run for x
#define f(x) int x;cin>>x;for(int i=0;i<x;i++)//for loop to take input and run for x
#define inpv(vector) int x;cin>>x;for(int i=0;i<x;i++){int val;cin>>val;vector.pb(val);}
#define printv(x) for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}//print vector
using namespace std;


//--------------------------------------------------------------------------------------------//  


int main() {
    w(x){
        int val;cin>>val;
        //when a*b=n then both values cannot be greater root n
        //similarly a*b*c then three values cannot be greater than cube root n
        int a,b,c;
        for(a=2;a*a*a<val;a++){
            if(val%a==0){
                break;
            }
        }
        int rem=val/a;
        for(b=a+1;b*b<rem;b++){
            if(rem%b==0){
                c=rem/b;
                        if(c<=b)    c=0; 
                        break;
                    }
                }
                if(a*b*c==val)  cout<<"YES\n"<<a<<" "<<b<<" "<<c<<endl;
                else cout<<"NO"<<endl;
    }
}
    

