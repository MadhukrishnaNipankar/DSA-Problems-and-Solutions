//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int help(int i,int j,int m,int n, vector<vector<int>>&dp){
        if(i>=0 && i<m && j>=0 && j<n){
             if(i == m-1 && j == n-1)return 1;
             if(dp[i][j] != -1)return dp[i][j];
             long long int ans = (help(i,j+1,m,n,dp) + help(i+1,j,m,n,dp))%1000000007;
             dp[i][j] = ans;
             return dp[i][j];
        }
        return 0;
       
    }
    long long int numberOfPaths(int m, int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        long long int ans = help(0,0,m,n,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends