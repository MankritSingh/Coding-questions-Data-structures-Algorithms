#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string,int>m;
	m.insert({"hargun",1});     //1 way of insertion
	m["aab"]=1;                 //2nd way of insertion
	
	m.insert({"abb",1});        //Can access through key or auto
	cout<<m["aab"]<<endl;
	for(auto &i:m){             //to print map we have to use auto/iterator
	    cout<<i.first<<" ";     //map elements are pair so remeber to use element.first
	}
	
	//some map functions
	//1 m.find()
	auto it=m.find("hargun1");
	if(it!=m.end())             //returns pointer to found element or return m.end
	cout<<"found:"<<(*it).first<<endl;
	else cout<<"Not found"<<endl;
	
	//2 m.erase erase a given key value pair.we can give a key or iterator as argument
	m.erase("aab"); //giving key as input
	m.erase(it)     //giving iterator as input
	return 0;
}
