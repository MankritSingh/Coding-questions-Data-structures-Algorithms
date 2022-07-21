#include <bits/stdc++.h>
using namespace std;
//ordered set:stores unique values in ordered way. logn complexity of poerations just like map
int main()
{
    set<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(100);
    s.insert(10);
    auto it=s.find(10);//returns iterator of the element else s.end()
    //set<int>::iterator it=s.find(10);  //same thing as above
    cout<<*it<<endl;
    //Way 1 to access all elements
    for(int it:s)  cout<<it<<endl;
    //Way 2 to access all elements
    //for(auto it=s.begin();it!=s.end();it++) cout<<*it<<endl;  
    s.erase(s.begin());//way1 pass iterator
    s.erase(10);//way 2 pass value
    return 0;
}
