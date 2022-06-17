/*Question:Selecting non adjacent elements,find the max sum in an array,given that the array is circular
ie its a circular array/list.
LINK:https://www.codingninjas.com/codestudio/problems/house-robber_839733
video:Striver d6

Approach:We think of using the same approach that we use in selecting non adjacent sum question,the only difference that
this question has in comparision with the non circular one,is that the the array/list is non curcular.
In case of circular list we have a problem.We cannot select the first and the last element together.
I thought of various way in which i can deal with this problem,like taking the first elemnt as defualt and deleating it later,
keeping the last and first element out etc,but the main problem I was facing was that we never know if we took the first element
or the last element in an answer or not.
SOLUTION: As we have clearly figured out that the first element and the last element cannot be in the answer together,
we should think about using it.What we can do is solve the questions with 2 cases, first case where we act like the first element 
does not exist,and the second case where we acts as the last case does not exist.
Now we have 2 answer,Just find the max of them and you have your answer.
*/

#define ll long long
ll sl(vector<int>& val,int n,vector<ll>& dp){
   if(n==0) return val[0];
    if(n==1) return max(val[0],val[1]);
    if(dp[n]!=-1) return dp[n];
    return dp[n]=max(val[n]+sl(val,n-2,dp),sl(val,n-1,dp));
}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<ll>dp(valueInHouse.size()+1,-1);
    if(valueInHouse.size()==1) return valueInHouse[0];
    ll ans1=sl(valueInHouse,valueInHouse.size()-2,dp);
    valueInHouse[0]=0;//we set the first element to 0 so it acts like it is included
    fill(dp.begin(),dp.end(),-1);
    ll ans2=sl(valueInHouse,valueInHouse.size()-1,dp);
    return max(ans1,ans2);
}
