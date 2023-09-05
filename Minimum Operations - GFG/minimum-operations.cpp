//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
//   recursive
    // int help(int n){
    //     if(n<=0)return INT_MAX;
        
    //     if(n == 1)return 1;
        
    //     int one = help(n-1)+1;
    //     int two = INT_MAX;
    //     if(n%2 == 0)
    //         two = help(n/2)+1;
            
    //     return min(one,two);
        
    // }
    
    // memoization
     int help(int n,vector<int>&dp){
        if(n<=0)return INT_MAX;
        
        if(n == 1)return 1;
        if(dp[n] != -1)return dp[n];
        
        int one = help(n-1,dp)+1;
        int two = INT_MAX;
        
        if(n%2 == 0)
            two = help(n/2,dp)+1;
        
        
        return dp[n] =  min(one,two);
        
    }
    int minOperation(int n)
    {
        vector<int>dp(n+1,-1);
        return help(n,dp);
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
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends