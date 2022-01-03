#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter the digits to fond LCM"<<endl;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
}
int lcm(int alen,int blen)
{
    do{
        int minval=min(alen,blen);
        int maxval=max(alen,blen);
        int ans=1;
        if(maxval%minval==0)
        {
            ans*=minval;
            minval/=minval;
            maxval/=minval;
        }
        else
        {
            return ans*minval*maxval;
        }
    }while(true);
}
