//the code is for nxn matrix.Just change the bounds of the loop to get the code for nxm matrix
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>ans;
    int arr[10][10];
    int n;
    int c=1;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=c++;
        }
    }
    
    // cout<<arr[1][3];
    
                int i=0,j=0;

        for(int k=0;k<n;k++){
            //1 j=0 i=0
            for(;j<n-k;j++)
            {
                // ans.push_back(arr[i][j]);
                cout<<arr[i][j]<<" ";
            }
            i++;
            j--;
            //2 j=n i=1
            for(;i<n-k;i++)
            {
                // cout<<i<<" "<<j<<endl;
                cout<<arr[i][j]<<" ";

              
            }
            j--;
            i--;
            //3 j=n-1 i=n
            for(;j>=0+k;j--)
            {
                cout<<arr[i][j]<<" ";
                
            }
            i--;
            j++;
            //4 j=0 i=n-1
            for(;i>=0+k+1;i--)
            {
                cout<<arr[i][j]<<" ";
                
            }
            j++;
            i++;
         }
    
    
   
   
	return 0;
}

