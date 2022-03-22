/*
IMPORTANT for all cases we have to make sure we deal with cases where the lower or upper bound value
is not found.here we have not done that

Upper bound and lower bound
lower_bound=When searching for a value in an array or vector eg x,the lower bound 
for an array or vector is the number itself or the number just greater than the number

upper_bound=When searching for a value in an array or vector eg x,the upper bound is the value greater
than x.While lower bound searches for equal and greater,upper bound searches for only value greater
than x.

Upper bound and lower bound in STL
they can be used with array as well as vector.When we use them with array we get pointer as output
and if the lower_bound or upper_bound is not present then lower_bound=upper_bound=arr+n where n=size of array
and when we use them with vector we get iterator as output and if the the upper_bound or lower_bound
is not present then we get lower_bound=upper_bound=vector.end()

we can also use lower and upper bound with sets and maps,but we have to use right syntax otherwise
the timecomplexity will be O(n) whereas with right syntax the time timecomplexity will be O(logn)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[]={1, 1, 2, 2, 2, 2, 4,4};
    int n=8,x=3;//n=size x=element to find
    int *lb=lower_bound(arr,arr+n,x);
    int *ub=upper_bound(arr,arr+n,x);
    cout<<"lower_bound :"<<*lb<<endl;
    cout<<"upper_bound :"<<*ub<<endl;
    
    //vector
    vector<int>vec={1, 1, 2, 2, 2, 2, 4,4};
    int x=4;
    auto lb=lower_bound(vec.begin(),vec.end(),x);
    auto ub=upper_bound(vec.begin(),vec.end(),x);
    cout<<"lower_bound :"<<*lb<<endl;
    cout<<"upper_bound :"<<*ub<<endl;
    
    //set set and map has different syntax
    set<int>s={1, 1, 2, 2, 2, 2, 4,4};
    int x=2;
    auto lb=s.lower_bound(x);
    auto ub=s.upper_bound(x);
    cout<<"lower_bound :"<<*lb<<endl;
    cout<<"upper_bound :"<<*ub<<endl;
    
    //map for map upper and lower bound only works on keys
    map<int,int>m={{1,1},{2,2},{4,4}};
    int x=2;
    auto lb=m.lower_bound(x);
    auto ub=m.upper_bound(x);
    cout<<"lower_bound :"<<(*lb).first<<"key's pair value:"<<(*lb).second<<endl;
    cout<<"upper_bound :"<<(*ub).first<<"key's pair value:"<<(*ub).second<<endl;
    
    //pair https://www.geeksforgeeks.org/implementation-of-lower_bound-and-upper_bound-in-vector-of-pairs-in-c/
    // Vector of Pairs lower_bound() for pair(x, y) will return an iterator pointing to the position
    //of pair whose the first value is greater than or equals x and second value is greater than equals to y.
	vector<pair<int, int> > vec;
    vec = { { 1, 3 }, { 1, 7 }, { 2, 4 },
            { 2, 5 }, { 3, 8 }, { 8, 6 } };
    auto lb=lower_bound(vec.begin(),vec.end(),make_pair(2,5));
    auto ub=upper_bound(vec.begin(),vec.end(),make_pair(2,5));
    cout<<"lower_bound :"<<(*lb).first<<" "<<(*lb).second<<endl;
    cout<<"upper_bound :"<<(*ub).first<<" "<<(*ub).second<<endl;
	return 0;
}
