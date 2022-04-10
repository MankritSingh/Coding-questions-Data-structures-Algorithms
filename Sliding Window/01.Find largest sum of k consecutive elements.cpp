#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[]={10,2,5,22,-10,9};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    int windowSize=3;
    int currentSum=0,ans=0;
    for(int i=0;i<windowSize;i++){  //calculating the sum of first K elements
        currentSum=currentSum+arr[i];
    }
    //cout<<currentSum<<endl;
    ans=currentSum;
    for(int i=0;i<arrSize-windowSize;i++){
        currentSum=currentSum-arr[0+i];
        currentSum=currentSum+arr[windowSize+i];
        //cout<<currentSum<<endl;
        ans=max(ans,currentSum);
    }
    cout<<"Answer:"<<ans<<endl;
	return 0;
}
