/* Question:Find the next smaller element to the left,if there is no greater element to the left,then give output as -1.
We have to give the output for the full given array and not just a single element.

Analysis:We can solve this problem using the array and a nested for loop but the time Complexitity will be O(n^2) we can do this with stack for faster solution.

Important:Whenever we have a loop where the inner loop is dependent on the outer loop ie the loop j dependent on the loop i then often stack provideds 
a better solution.

Here we will traverse the array from left to right.We will store elements that are smaller than the elements that come along the way 
as we already know that we have smaller value element ahead.

Code:
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    std::vector<int> input,output;
    stack<int> s;
    int length;
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
            while(!s.empty() && s.top()>=input[i])
                s.pop();
            if(s.empty())
                output.push_back(-1);
            else
                output.push_back(s.top());
        }
        s.push(input[i]);
    }
    for(int i=0;i<length;i++)
        cout<<output[i]<<" ";
}
