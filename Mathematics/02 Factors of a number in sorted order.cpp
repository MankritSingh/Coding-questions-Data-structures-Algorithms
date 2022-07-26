int main() {
    int n;
    cin>>n;
    vector<int>factorSmall;
    vector<int>factorBig;
    for(int i=1;i<=sqrt(n);i++){  //can also write i*i<=n
        if(n%i==0){
            if(n/i!=i){
                factorBig.push_back(n/i);
            }
            factorSmall.push_back(i);
        }
    }
    reverse(factorBig.begin(),factorBig.end());   
    factorSmall.reserve(factorSmall.size()+factorBig.size());   //reserve reserves memory for the vector so it saves time of expanding if needed
    factorSmall.insert(factorSmall.end(),factorBig.begin(),factorBig.end());  //insert is used to insert element 
    for(int factor:factorSmall) cout<<factor<<" ";
	return 0;
}
