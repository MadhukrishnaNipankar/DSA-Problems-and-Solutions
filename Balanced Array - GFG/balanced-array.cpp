//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minValueToBalance(int a[], int n)
    {
      int leftHalfSum = 0; 
      int tempPtr = 0;
      for(int i=0;i<n/2;i++){
          leftHalfSum+=a[i];
          tempPtr++;
      }
      
      
       int rightHalfSum = 0; 
      for(int i=tempPtr;i<n;i++){
          rightHalfSum+=a[i];
      }
    //   cout<<leftHalfSum<<endl;
    //   cout<<rightHalfSum<<endl;
      
      return abs(leftHalfSum-rightHalfSum);
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.minValueToBalance(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends