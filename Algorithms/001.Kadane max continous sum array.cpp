/*
Question:Find the max continous sum in a given array which contains positive as well as negative elements.

Analysis:The concept that kadane algorithm uses is that at stage we have two choices,
1)we can continue the sub array selection ie will include the current element in our sum
2)we will select just the current element.
we will choice the max of the two above choices.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) { //nums is the question array
        int maxg=nums[0];
        int maxcurrent=nums[0];
        for(int i=1;i<nums.size();i++){
            maxcurrent=max(nums[i],maxcurrent+nums[i]);
            maxg=max(maxg,maxcurrent);
        }
        return maxg;
    }
};
