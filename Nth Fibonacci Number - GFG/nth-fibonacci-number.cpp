//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define MOD 1000000007

class Solution {
  public:
    int fib(int n, vector<int>&dp){
        if(n == 1 || n == 2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (fib(n-1, dp)+fib(n-2, dp))%MOD;
    }
    int nthFibonacci(int n){
       vector<int>dp(n+1,-1);
       return fib(n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends