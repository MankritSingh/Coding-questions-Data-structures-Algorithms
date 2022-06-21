/*question link:https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241
Question:A similar path traversal problem where we can only go either right or down but in this case we have obstacles
present too.We have a matrix given where -1 is obstacle and 0 in normal path.

Analysis:The question is quite similar to the original question and therefore will have a similar answer too,
we need to understand what changes we have to make to get the answer for the added constriant.
There are 2 things to note
  1)we need to handle the case when we encounter -1.It is simple to understand that when we are on -1,it means we cannot go
  any further therefore,there is no way THROUGH -1.There we return 0 when we encounter
  2)IMPORTANT: When doing similar question or variation of a question,Always think how base condition will be impacted.
  here our base condition will have to be modified as now we can no longer just go down or just go right and reach destination.
  As now if we need to make sure there is no -1 between the edge(prevoius base condition) and destination
*/

//recursive/memoization solution:
const int modular=1e9+7;
int s(int n, int m, vector< vector< int> > &mat,vector< vector< int> > &dp){
    if(mat[n][m]==-1) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(m==0){//base condition is modified as we may have a -1 in the edge and destination
        int count=0;
        while(n>=0) count+=mat[n--][m];
        if(count==0) return 1;
        else return 0;
    };
    if(n==0){
    int count=0;
    while(m>=0) count+=mat[n][m--];
    if(count==0) return 1;
    else return 0;
    };
    long long ans=(s(n-1,m,mat,dp)+s(n,m-1,mat,dp));
    ans=ans%modular;
    return dp[n][m]=ans;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return s(n-1,m-1,mat,dp);
}

//Iterative
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));//we make a dp array that has extra 0 on left col and upper row
    dp[1][1]=1;//start is 1, if we get -1 at start,it is changed ahead
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(mat[i-1][j-1]==-1){
                dp[i][j]=0;
            }
            else if(i==1 && j==1) continue;//added so dp[1][1] is not updated
            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%modular;
        }
    }
    return dp[n][m];
    
    
}
