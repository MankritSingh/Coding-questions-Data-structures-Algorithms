/*
Question Link:https://atcoder.jp/contests/dp/tasks/dp_a
*/ 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int


int main()
{
    int n,ncopy;
    vector<int>v;
    cin>>n;
    ncopy=n;
    while(n--){
        int val;
        cin>>val;
        v.push_back(val);
    }
    if(ncopy==2)
    {
        cout<<abs(v[1]-v[0]);
    }
    else
    {
        int stone1=abs(v[1]-v[0]);
        int stone2=abs(v[2]-v[0]);
        for(int i=3;i<v.size();i++)
            {
                int temp=min(stone2+abs(v[i]-v[i-1]),stone1+abs(v[i]-v[i-2]));
                stone1=stone2;
                stone2=temp;
            }
            cout<<stone2; 
    }

}
