/*
Question:Factorial
Analysis:The answer is almost identical to that of the fibonacci.
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long arr[N];
//Factorial
int fact(int n){
    if(n==0) return 1;
    if(arr[n]!=-1) return arr[n];
    return arr[n]=n*fact(n-1);
}



int main() {
    int n;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        memset(arr,-1,N);
        cout<<fact(val)<<endl;
    }

	return 0;
}
