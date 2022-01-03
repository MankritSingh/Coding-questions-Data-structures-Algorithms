/* Question:we are given an array and we need to find the sum of the given ranges,for eg sum[0,6],sum[1,6]  etc.
   Analysis: *IMPORTANT* When we have questions where the number of test cases are of greater order ie are big in number.We often have to solve these type of 
   problems using dynamic programming.If the number of queries are less then the preproccesing wont help much but still may be considered.
   
   Naive approach:The first approach that comes in our mind is to simply find the sum of the given range by using array traversal.The time complexity in this case will 
   O(n) where n is the length of the array.For say m number of queries the time complecity comes out to be O(n*m).Here if the value of m is big we will encounter a problem
   with the time taken to solve the problem.
   
   Prefix sum approach:We will find the prefix sum of the given array.First we make an array of the same size,then we find the consective sums as we go on.
   Eg [1,3,4,5] the array we make will be 
   1)[1]            
   2)[1,4]              The sum of 1 and 3
   3)[1,4,8]            The sum of 1,3 and 4   
   4)[1,4,8,13]         The sum of 1,3,4and 5
  We can easily find the sum of range starting from 0 by just seeing the array element.eg sum[0,3]=arr[3] and so on.
  For other queries we simply use the logic like sum[0,6]=sum[0,2]+sum[2,6] therefore sum[2,6]=sum[0,6]-sum[0,2]
                                                                                      sum[2,6]=dp[6]-dp[2-1]
*/
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
        dp[i]=dp[i-1]+word[i-1];
    }
    while(q--)
    {
        cin>>l>>r;
        int sum=dp[r]-dp[l-1];
        cout<<sum<<endl;
    }
    return 0;
}
