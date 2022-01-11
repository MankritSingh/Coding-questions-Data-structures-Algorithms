/*
Question:Fibonacci Series using Dp

Important:To construct the dp solutin what we do is that first we form the brute force recursion answer.Then we try to understand what steps we can store to reduce
the time taken and then store those values.

Analysis: We usually solve fibonacci using recursion but the time complexity for it gets to 2^n.When we construct the recursion tree we observe that we are calculating
the same values again and again.Therefore we use dp and store the values that we calculate.This reduces the complexity to O(n).
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long arr[N];//here people usually use the name dp for the array i have used arr in this case

//Fibonacci series
int fib(int n){
    if(n==0) return 0;//first element of series
    if(n ==1) return 1;//second element of series
    if(arr[n]!=-1) return arr[n];//we will check if we have already calculated the value.If yes then we directly get the answer
    return arr[n]=fib(n-1)+fib(n-2);// we will assign the answer to dp array arr[n] and return the value both together.
}



int main() {
    int n;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        memset(arr,-1,N);//memset is used to set the entire array to -1.memset has fixed values so check and use.
        cout<<fib(val)<<endl;
    }

	return 0;
}
