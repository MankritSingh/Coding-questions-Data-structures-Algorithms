/*
video seen:https://www.youtube.com/watch?v=p9T-fE1g1pU
Question:In Stock span problem we are given an array of elements.we have to give array in output where for each corresponding element
we give the number of consecutive days when the price was less than the current day.

Analysis:This question is actually a question where we have to find consecutive smaller elements on the left.When finding consecutive smaller or greater element
we must understand what we are basically doing.In case of consecutive smaller element on left,we are basically searching on left for an element greater than
the considered one,therefore this is the same as find next greatest element on left.Similary if we were to find consecutive greater element of
left is same as finding next smaller element on left.

Code:
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int length;
    vector<int>input,output;
    stack<pair<int,int>>s;
    cin>>length;
    for(int i=0;i<length;i++)
    {
        int val;
        cin>>val;
        input.push_back(val);
    }
    for(int i=0;i<length;i++)
    {
        if(s.empty())
        {
            output.push_back(-1);
        }
        else
        {
            while(!s.empty() && s.top().first<=input[i])
            {
                s.pop();
            }
            if(s.empty())
                output.push_back(-1);
            else
                output.push_back(s.top().second);
        }
        s.push({input[i],i});
    }
    for(int i=0;i<length;i++)
        cout<<i-output[i]<<" ";
}
