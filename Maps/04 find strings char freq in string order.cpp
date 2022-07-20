#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char,int>m;
    string word;
    cin>>word;
    for(char ch:word) m[ch]++;
   // for(auto it:m)  cout<<it.first<<" "<<it.second<<endl;
    for(char ch:word){
        if(m[ch]!=0){
            cout<<ch<<" "<<m[ch]<<endl;
            m[ch]=0;
        }
    }
    return 0;
}
