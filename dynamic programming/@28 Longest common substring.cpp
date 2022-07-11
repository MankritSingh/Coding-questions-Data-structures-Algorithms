/*Question:Longest common Substring.

Analysis:This question is similar to longest common subsequence.This question uses the concept of continous selection.
Doing this in recursion becomes difficult and we need to carry an extra variable so we can compare the continous answer with the new forming answer.
We can do this in the sameway as subsequence with a minor change.When the characters are matching ,we will incremnet the dp value by 1 but when its does not match
at this stage the continous link is broken.THerefore we will assign the value 0 to the the dp block.

*/

int lcs(string &str1, string &str2){
    int len1=str1.length();
    int len2=str2.length();
    vector<vector<int>>dp(str1.length()+1,vector<int>(str2.length()+1,0));
    for(int i=1;i<len1+1;i++){
        for(int j=1;j<len2+1;j++){
            if(str1[i-1]==str2[j-1])    dp[i][j]=1+dp[i-1][j-1];
        }
    }
    int maxVal=0,indI=0,indJ=0;
    for(int i=1;i<len1+1;i++){
        for(int j=1;j<len2+1;j++){
            if(dp[i][j]>maxVal){
                maxVal=dp[i][j];
                indI=i;indJ=j;
            }
        }
    }
    return maxVal;
}
