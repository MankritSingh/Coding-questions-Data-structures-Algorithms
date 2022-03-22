/*Question:In a given array,find a given element and its number of occurances
Question link:https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1/#
Answer:We use binary search along with upper bound and lower bound to find the answer in logn.if we use normal binary search
the time complexity will be logn+occurance ie it will be logn+n=O(n) in worst case.
*/
//the solution function using stl lower_bound and upper_bound
int count(int arr[], int n, int x) {
	    int *lb=lower_bound(arr,arr+n,x);
        int *ub=upper_bound(arr,arr+n,x);
        // cout<<lb-arr<<" "<<*ub;
        if(lb==arr+n) return 0;
        else return (ub-lb);        
	}
