/* 
Question:Given an 1D array that is used to build a histogram. find the max area one can generate from the histogram by forming a rectangle in the histogram.
ie find the largest(in terms of area) rectangle that can be formed in the histogram.

Brute force:for each element we find the max area that we can form with the given element.Time complexity O(n^2)

Analysis:On thinking about the problem well,we observe that to form a rectangle,we need a row of equal or greater area on both its neibhouring sides.
that is we can form a rectangle till we find an element smaller that the one we are comparing.Therefore we need to find the nearest smaller element in other words.
Using this we can easily find the max area.IMPORTANT thing to note is that we need the range and storing -1 for NSR and NSL just like usual will not be correct.
we will have a pseudo left and pseudo right that will help us make sure that for min value of our input we get correct answer. 
1)find the NSR and NSL for each element
2)The area for each element we traverse we get the max area possible by using the given element by seeing the range it covers from its NSR and NSL.
therefore we need to store the index of the NSR and NSL too.We will use vector pair to store the value and index together.
3)Area=element*(range).
Time complexity:We will traverse the array twice.Once to find NSR and NSL and once to find area.O(2N)=O(N)

*/
#include <bits/stdc++.h>
using namespace std;

    int largestRectangleArea(vector<int>& heights) {
    //NSL
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
