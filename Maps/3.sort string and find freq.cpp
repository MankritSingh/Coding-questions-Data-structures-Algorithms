/*
Question:given string arrange them lexographically and find thier frequency

Analysis:Use find() function to see if the string is present or not.If present increase its value by 1 else insert element in map
with frequency 1
*/#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string,int>m;
	std::vector<string>v ;
    int len;
    cin>>len;
    for(int i=0;i<len;i++){
        string val;
        cin>>val;
        v.push_back(val);
    }
    for(int i=0;i<len;i++){
        auto it=m.find(v[i]);
        if(it!=m.end()) m[v[i]]+=1;
        else{
            m[v[i]]=1;
        }
    }
    for(auto it:m){
        cout<<"String:"<<it.first<<" "<<"Freq:"<<it.second<<endl;
    }
}
