//video seen:https://youtu.be/XjtYsFjXtoE
#include<bits/stdc++.h>
using namespace std;
int main(){

	//bit tricks
	// (1) odd even check
	int a=21;
	if(a&1) cout<<"odd";    //do and with last bit.if last bit is 1 then its odd
	else cout<<"even";
	
	// (2) multiply divide by 2
	cout<<(a<<1)<<endl;//multiply by 2
	cout<<(a>>1)<<endl;//divide by 2

	// (3) upper and lower case conversion
	//1 difference between a and A is 32
	cout<<'a'-'A'<<endl;
	char letter='b';
	letter-=32;
	//2 when we see binary representation we observe that the binary of same letter is same except the fact that for lower
	//case letter the 5th bit is set whereas for upper case letter its unset
	letter='k'&'_'; //unset 5th bit
	cout<<letter<<endl;
	letter='K'| ' ';//set 5th bit
	cout<<letter<<endl;

	// (4) unset all bits till a given n'th bit(similar logic for set all bits till n'th bit)
	x=0b1100110;
	cout<<(x & ~((1<<5)-1));//unset till 4th bit

	// (5) check if power of 2 or not
	int nums=128;
	if(nums&(nums-1)) cout<<"not power of 2";
	else cout<<"Power of 2";

	return 0;
}
