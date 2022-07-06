/* IMP:We have done this question with recursion before.Make sure to read that.It also shows how we can print the LCM
Question:https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879

Analysis:In this question we are asked to find the longest common subsequnce of two given strings.
We know that we can solve this by brute force but first finding all the subsequences of the given strings and then finding the longest common amongts them.
We solve this question by keeping a pointer ie taking the index,of the last character of both the strings.
Now we compare them,we can have 2 results->first they match.Just add a 1 and reduce the index of both the indexes
                                         ->second they dont match.Now we are confused that if move index of first string the that character may appear later and the 
                                         same thing may happen for the second string too.Therefore we make both recursion call(in first call reduce the first string indecx
                                         and in the second call reduce the second strings index) and choose the max amongs them.
 This gives us our answer.
 */
 //recursive written in earlier post.check the dp github
 //iterative
 #include <vector>
int lcs(string s, string t)
{
    int lenS=s.length();
    int lenT=t.length();
	vector<vector<int>>dp(lenS,vector<int>(lenT,0));
    int flag=0;
    for(int i=0;i<lenT;i++){  //setting 1 way if the first character matches with any character and then 1 for all the other characters ahead too as we now have 1 way
        if(s[0]==t[i])    flag=1;
        dp[0][i]=flag;
    }
    for(int i=1;i<lenS;i++){
        for(int j=0;j<lenT;j++){
            if(s[i]==t[j])    dp[i][j]=1+dp[i-1][j-1];
            else{
            int notTake=dp[i-1][j];
            int take=0;
            if(j>0){
                take=dp[i][j-1];
            }
            dp[i][j]=max(take,notTake);
            }
        }
    }
    return dp[lenS-1][lenT-1];
    
}
//space optimized solution
#include <vector>
int lcs(string s, string t)
{
    int lenS=s.length();
    int lenT=t.length();
	//vector<vector<int>>dp(lenS,vector<int>(lenT,0));
    vector<int>prev(lenT,0);
vector<int>curr(lenT,0);
    int flag=0;
    for(int i=0;i<lenT;i++){
        if(s[0]==t[i])    flag=1;
        prev[i]=flag;
    }
    for(int i=1;i<lenS;i++){
        for(int j=0;j<lenT;j++){
            if(s[i]==t[j])    curr[j]=1+prev[j-1];
            else{
            int notTake=prev[j];
            int take=0;
            if(j>0){
                take=curr[j-1];
            }
            curr[j]=max(take,notTake);
            }
        }
        prev=curr;
    }
    return prev[lenT-1];
    
}
