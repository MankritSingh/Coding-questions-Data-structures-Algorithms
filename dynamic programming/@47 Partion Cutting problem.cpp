/*Question:We are given a stick of length n and array of cuts.The cuts array has value where we put a cut.
The cost of putting a cut is the length of the stick.

Analysis:We observe the similarity between this and MCM.We can start with any index.Now to avoid overlap between the cut values,
we will sort the cut values ascendingly.Because of this ,the two subparts will now be independent of each other.
Now the cost of cutting the stick is equal to the length of the stick.So how do we calculate this?
to do this,we will add a 0 at start and the length of stick n at end.
Now to get the length of stick at any time,we just do cuts[j+1]-cuts[i-1].j+1 and i-1 as we will run loop from 1 to c(length of cuts array)
Similar to MCM,each partition is solved and saved
*/

//recursive+memization
#include <bits/stdc++.h> 
int sol(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
    if(i>j)    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    //select each element as the first element
    //ie form partitions
    int ans=INT_MAX;
    for(int k=i;k<=j;k++){
        int cost=(cuts[j+1]-cuts[i-1])+
            sol(cuts,i,k-1,dp)+sol(cuts,k+1,j,dp);
        ans=min(ans,cost);
    }
    return dp[i][j]=ans;
    
}

int cost(int n, int c, vector<int> &cuts){
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return sol(cuts,1,c,dp);
}
