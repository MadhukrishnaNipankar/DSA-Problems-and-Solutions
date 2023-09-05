//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int help(int n,vector<int>&dp){
	        if(n<=1)return 1;
	        if(dp[n]!= -1)return dp[n];
	        
	        int one = help(n-1,dp);
	        int two = help(n-2,dp);
	        
	        return dp[n] =  (one+two)%1000000007;
	        
	    }
		int nthPoint(int n){
		    vector<int>dp(n+1,-1);
		   return help(n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends