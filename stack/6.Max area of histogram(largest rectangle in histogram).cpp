#include <bits/stdc++.h>
using namespace std;

    int largestRectangleArea(vector<int>& heights) {
    vector<int>input,outputLeft;
    stack<pair<int,int>>sLeft;
    int len;
    int pseudoLeft=-1;
    input=heights;
    len=input.size();
    for(int i=0;i<len;i++)
    {
        if(sLeft.empty())
            outputLeft.push_back(pseudoLeft);
        else
        {
            while(!sLeft.empty() && sLeft.top().first>=input[i])
                sLeft.pop();
            if(sLeft.empty())
                outputLeft.push_back(pseudoLeft);
            else
                outputLeft.push_back(sLeft.top().second);
        }
        sLeft.push({input[i],i});
    }
    
    //NSR
    vector<int>outputRight;
    stack<pair<int,int>>sRight;
    int pseudoRight=len;
    for(int i=len-1;i>=0;i--)
    {
        if(sRight.empty())
            outputRight.push_back(pseudoRight);
        else
        {
            while(!sRight.empty() && sRight.top().first>=input[i])
                sRight.pop();
            if(sRight.empty())
                outputRight.push_back(pseudoRight);
            else
                outputRight.push_back(sRight.top().second);
        }
        sRight.push({input[i],i});
    }
    reverse(outputRight.begin(),outputRight.end());
    
    vector<int> width;
    for(int i=0;i<len;i++)
         width.push_back((outputRight[i]- outputLeft[i]-1)*input[i]);
        
    //  for(int i=0;i<len;i++)
    //      cout<<width[i]<<" ";
    
    int ans= *max_element(width.begin(),width.end());
        return ans;
    }

int main()
{
    int len;
    long long answer;
    vector<int>input;
    cout<<"Enter the lenght of array"<<endl;
    cin>>len;
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<len;i++)
    {
        int val;
        cin>>val;
        input.push_back(val);
    }
    answer=largestRectangleArea(input);
    cout<<answer;
    
}
