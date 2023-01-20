#include<bits/stdc++.h>
using namespace std;
int main(){
    int number=100;
	int x=0b10; //represent binary numbers like this,with 0b prefix.It will be printed as 3
	string num="110";
	int stringToInt=stoi(num,0,2);//covert string to number.parameter are(string name,0,base)keep base as 10 for decimal
	int stringToll=stoll(num,0,10);//covert string to ll.
	num=to_string(number);//convert number to string(decimal)
}
