#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cout<<"Enter row n and columns m"<<endl;
	int input[100][100];
	int sum[100][100]{0};
	long long total=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)//input
	{
	    for(int j=1;j<=m;j++)
	    {
	        int val;
	        cin>>val;
	        input[i][j]=val;
	    }
	}
	//prefix calculation
	for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=m;j++)
        sum[i][j]=input[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    }
    
    //answer derivation
	cout<<"Enter no of queries"<<endl;
	int q;
	cin>>q;
	while(q--)
	{
	    int a,b,c,d;
	    long long answer;
	    cout<<"Enter the row and col of first and last element a,b,c,d"<<endl;
	    cin>>a>>b>>c>>d;
	    answer=sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
	    cout<<answer<<endl;
	}
	
	
	
// 	for(int i=0;i<n;i++)
// 	{
// 	    for(int j=0;j<m;j++)
// 	    {
// 	          cout<<input[i][j]<<" ";
// 	    }cout<<endl;
// 	}
	return 0;
}
