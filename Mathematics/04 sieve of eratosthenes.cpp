//time complexity log(log(n))

int main() {
    const int n=100;
    vector<int>primes(n,1);//can keep vector of bool. dont need to change anything just vec data type as in c++ 0 is false
    primes[0]=primes[1];  
  for(int i=2;i<=n;i++){//can also do i*i<=n
        if(primes[i]==1){
            for(int j=2*i;j<=n;j+=i){ //can also do j=i*i
                primes[j]=0;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(primes[i]==1)    cout<<i<<" ";
    }
	return 0;
}
