//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        if(n == 1)return nums[0];
        if(n == 2)return min(nums[0],nums[1]);
        
        
        
  int i;
  int left = 0, right = n-1, minVal = INT_MAX;

  while (left <= right) {
    if (nums[left] < nums[right]) {
      minVal = min(minVal, nums[left]);
      break;
    }
    int mid = left + (right - left) / 2;

    if (nums[left] <= nums[mid]) {
      minVal = min(minVal, nums[left]);
      left = mid + 1;
    } else {
      minVal = min(minVal, nums[mid]);
      right = mid - 1;
    }
  }
  return minVal;
        
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends