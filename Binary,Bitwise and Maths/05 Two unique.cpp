    vector<int> singleNumber(vector<int> nums) 
    {
        int len=nums.size();
        vector<int>v={0,0};
        int gt=0;
        for(int i=0;i<len;i++){
            gt=gt^nums[i];
        }
        int j=0;
        for(int i=0;i<31;i++){
            if((gt&(1<<i))!=0){//take caare of brackets
                j=i;
                break;
            }
        }
        for(int i=0;i<len;i++){
            if( ((1<<j)&nums[i])!=0){//brackets
                v[0]^=nums[i];
            }else{
                v[1]^=nums[i];
            }
        }
        if(v[0]>v[1]) swap(v[0],v[1]);
        return v;
    }
