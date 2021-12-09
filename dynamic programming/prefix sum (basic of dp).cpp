#include<iostream>
using namespace std;

int main(){
    int n,q,l,r;
    int dp[1000001]={0};
    string word;
    cin>>n>>q;
    cin>>word;
    for(int i=1;i<=word.size();i++)
    {
        dp[i]=dp[i-1]+word[i-1]-'a'+1;
    }
    while(q--)
    {
        cin>>l>>r;
        int sum=dp[r]-dp[l-1];
        cout<<sum<<endl;
    }
    return 0;
}
