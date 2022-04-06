#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=0b10; //represent binary numbers like this,with 0b prefix.It will be printed as 3

	//binary leftshift and rightshift
	//cout<<(1<<0);//1 left shift 0 is 1 therefore it starts from 0th bit.1<<1 is 2
	//cout<<(x<<1);//moves all binary digits ahead by 1
	//cout<<(6>>1);//moves all binary digit right ie behind by 1 and discard the last bit
	unsigned int example=(1LL<<32)-1; //unsigned can work with 32 bits and 
	//signed ie general int can work with 31 bits


	//counting set bit
	x=0b1100101;
	int count=0;
	int i=0b1;
	int c=0;
	while(i<=x){		//we can also use for loop where i can range to 32 for 32 bit number
		if(x&(1<<c)) count++;
		c++;
		i=(i<<1);
	}
	cout<<count<<endl;
	cout<<__builtin_popcountll(x)<<endl;//built function to set bit

	//setting a bit
	x=0b1101;
	cout<<(x | (1<<1))<<endl;
	//unsetting a bit
	cout<<(x & ~(1<<2))<<endl; //~ this is the inversion operator tilda.It will make all 1s 0 and all 0s 1
	//toggle a bit
	cout<<(x ^ (1<<3))<<endl;//using xor to toggle
	
	return 0;
}
