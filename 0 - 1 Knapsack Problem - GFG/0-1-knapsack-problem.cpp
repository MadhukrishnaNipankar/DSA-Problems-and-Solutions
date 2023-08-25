//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // Initializing a 2D DP array

    // Filling up the DP array
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W]; // Maximum value for the given knapsack capacity
}
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends