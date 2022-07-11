/*Question:https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493
Question:We have to find the shortest supersequnce of 2 strings.supersequence means that from the made string,we should get the two strings as a subsequnce

Analysis:When we read the question,using LCS comes to our mind.
Basically we will keep the LCS as it is,and add the remainig characters of both the string to make the supersequence.
the length of supersequnce is given by a.len+b.len-LCS
There are 2 ways of printing the answer.
Using the matrix or keeping pointer of the two strings and on the LCS.

*/

#include<bits/stdc++.h>
string shortestSupersequence(string a, string b)
{
    int alen=a.length();
    int blen=b.length();
	vector<vector<int>>dp(alen+1,vector<int>(blen+1,0));
    for(int i=1;i<alen+1;i++){
        for(int j=1;j<blen+1;j++){
          if(a[i-1]==b[j-1])    dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
  //FIRST WAY TO PRINT USING MATRIX
    string ans="";
        int indi=alen,indj=blen;
    while(indi>=1 && indj>=1){
        if(a[indi-1]==b[indj-1]){
            ans+=a[indi-1];
            indi--;indj--;               
        }
        else if(dp[indi-1][indj]>dp[indi][indj-1]){
            ans+=a[indi-1];
            indi--;
        }
        else {ans+=b[indj-1];indj--;}
    }
    if(indi>0){
        while(indi>=1){
            ans+=a[indi-1];
            indi--;
        }
    }
    else{
                while(indj>=1){
            ans+=b[indj-1];
            indj--;
        }
    }
    reverse(ans.begin(),ans.end());
    //cout<<ans;
    return ans;
  
    //SECOND WAY TO PRINT  
//     string ans="";
//     int indi=alen,indj=blen;
//     while(indi>=1 && indj>=1){
//         if(a[indi-1]==b[indj-1]){
//             ans+=a[indi-1];
//             indi--;indj--;               
//         }
//         else if(dp[indi-1][indj]>dp[indi][indj-1]){
//             indi--;
//         }
//         else indj--;
//     }
//     reverse(ans.begin(),ans.end());
    
//     indi=0;indj=0;
//     int subIndex=0;
//     string finalans="";
//     while(indi<alen && indj<blen){

//         if( a[indi]==b[indj] && a[indi]==ans[subIndex]){
//             finalans+=a[indi];indi++;indj++;subIndex++;
//         }
//         else if(a[indi]==ans[subIndex]){
//             finalans+=b[indj];
//             indj++;
//         }
//                 else if(b[indj]==ans[subIndex]){
//             finalans+=a[indi];
//             indi++;
//         }
//         else if(indi<indj){
//             finalans+=a[indi];
//             indi++;
//         }
//         else{
//             finalans+=b[indj];
//             indj++;  
//         }
//     }
//             if(indi>=alen){
//             while(indj<blen){finalans+=b[indj];indj++;}
//         }
//         if(indj>=blen){
//             while(indi<alen){finalans+=a[indi];indi++;}
//         }
//     return finalans;
}
