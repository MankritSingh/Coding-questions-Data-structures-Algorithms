/*
Question:https://leetcode.com/problems/divisor-game
video:https://www.youtube.com/watch?v=1UW3SxuITKs

*/
class Solution {
int dp[1001]={-1};
public:
    bool divisorGame(int n){
        memset(dp,-1,sizeof(dp));
        return divisorGame1(n);
        
    }
    int divisorGame1(int n) {
        if(dp[n]!=-1) return dp[n];
        else if (n==1) return dp[n]=0;
        else{
            for(int i=1;i<n;i++){
                if(n%i==0){
                    if(!divisorGame1(n-i)){
                        return dp[n]=1;
                    }
                }
            }
            return 0;
        }
    }
};
