//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long currentSum = 0;
        long long maximumSoFar = INT_MIN;
        
        
        for(int i=0;i<n;i++){
            currentSum +=arr[i];
            maximumSoFar = max(maximumSoFar,currentSum);
            
            if(currentSum<0){
                currentSum = 0;
            }
        }
        
        
        return maximumSoFar;
     
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends