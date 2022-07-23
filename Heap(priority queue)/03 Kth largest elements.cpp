//Question link:https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1
/*Question:Find the k largest elements
Analysis:This is a question of min heap as we have to find the k largest.But we have used max heap here by applying negative sign while adding and removing elements
Also when we print the k largest elements,we were expected to print them in descending order.We may think we need to sort the vector but one thing to note is
that we remove elements from heap,we remove 1 by 1 therefore the element removed is either max or min.Therefore just reverse the vector
*/
 vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int>minh;
        for(int i=0;i<n;i++){
            minh.push(-arr[i]);
            if(minh.size()>k)   minh.pop();
        }
        vector<int> ans;
        while(!minh.empty()){
            int val=minh.top();
            val*=-1;
            ans.push_back(val);
            minh.pop();
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
