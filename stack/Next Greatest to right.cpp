Video seen:https://www.youtube.com/watch?v=NXOOYYwpbg4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=3
/* Question:Find the next greatest element to the left,if there is no greater element to the left,then give output as -1.
We have to give the output for the full given array and not just a single element.

Analysis:We can solve this problem using the array and a nested for loop but the time Complexitity will be O(n^2) we can do this with stack for faster solution.
Important:Whenever we have a loop where the inner loop is dependent on the outer loop ie the loop j dependent on the loop i then often stack provideds a better solution.
Here we will traverse the array from right to left.We will store elements that are greater than the elements that come along the way ie the left most elements
as we already know that we have greater value element ahead.

Code:
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> //for reverse()
using namespace std;

int main() {
    stack<int> stack;
    vector<int> input={1,3,2,4};
    vector<int> output;
    
    int len=input.size();
    for(int i=len-1;i>=0;i--)//traverse the input right to left
    {
        if(stack.empty())
        {
            output.push_back(-1);
        }
        else
        {
            while((!stack.empty()) && stack.top()<=input[i])// never do even seek on empty stack it gives segment error.
            {
                stack.pop();
            }
            if(stack.empty())
                output.push_back(-1);
            else
                output.push_back(stack.top());
        }
        stack.push(input[i]);
    }
    reverse(output.begin(), output.end());
    for(int i=0;i<len;i++)
        cout<<output[i]<<"  ";
	
	return 0;
}
