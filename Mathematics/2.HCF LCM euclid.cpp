 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
int hcf(int a,int b){
    int minval=min(a,b);
    int maxval=max(a,b);
    if(maxval%minval==0)
        return minval;
    else
        hcf(minval,maxval%minval);
    // if(b==0) return a;
    // return hcf(b,a%b);
}

int lcm(int a,int b)
{
  return ((a*b)/hcf(a,b));  
}
 

int main()
{
 int num1,num2,answer;
 cin>>num1>>num2;
 answer=hcf(num1,num2);
 cout<<"HCF:"<<answer<<endl;
 answer=lcm(num1,num2);
 cout<<"LCM:"<<answer<<endl;
}
