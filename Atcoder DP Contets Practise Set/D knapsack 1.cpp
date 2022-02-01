/*
Question:The knapsack problem is a famous dp problem and its concept and variation are seen throughout many dp problems.We are given an array of values an thier corresponding weights.
we are also given the max weight.We have to maximize our profit by doing an optimal choice.
Analysis:This question introduces a new concept that is there are two variable changing ie multidimensional dp.The appraoch we use to solve this question is quite simple and
is used in many dp question.Lets look at the last element of the array.We now see what will happen if we use this element and what will happen if we do not choose this element.
ie we form a decision tree with one branch when we take the elemnent and one branch when we dont take the element.we do this for all element as we progress further down the tree.
Now this will of  complexity O(2^n) ie we will have 2^n nodes.Now if we will try to elminate some nodes/steps with some simple observation.If the weight limit-weight of element is 
a negative number ie if we dont have enough space we will not continue that decision tree further.this saves us some steps.
the base condition here will be that if elements of array are over or is the weight limit is over we return 0.
Now to apply dp to this question,we have dp[n][w] where n=index of element w=weight. we save the calculations.But here we notice that we can only use the dp value when we have
exact same case ie when the index of element is same but the weight will differ as we make choices so we will have to do lot more calculation/steps than that we were doing for
the previous questions.
*/



#include <bits/stdc++.h>
using namespace std;
long long dp[110][100010];
int val[105],wt[105];

long long kp(int n,int wLeft){
    //base condition
    if(n<0 || wLeft==0) return 0;
    if(dp[n][wLeft]!=-1) return dp[n][wLeft];
    //what will we return when we dont select the current element
    long long ans= kp(n-1,wLeft);//w remains same
    //what we will return if we select the current element
    if(wLeft-wt[n]>=0)
       ans=max(ans,kp(n-1,wLeft-wt[n])+val[n]) ;
    return dp[n][wLeft]=ans;
    
}

int main() {
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
	   cin>>wt[i]>>val[i]; 
	}
	memset(dp,-1,sizeof(dp));
	cout<<kp(n-1,w);
	return 0;
}
