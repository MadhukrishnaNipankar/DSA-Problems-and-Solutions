//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   memoization
    int help(int i, int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i>=n || j>=m )return 0;
        if(grid[i][j] == 1)return 0;
        if(i == n-1 && j == m-1)return 1;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        dp[i][j] =( help(i,j+1,n,m,grid,dp)+help(i+1,j,n,m,grid,dp))%1000000007;
        return dp[i][j];
    }
    
    
    
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // memoization
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return help(0,0,n,m,grid,dp);
        
        // Tabulation
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(grid[n-1][m-1] == 1)return 0;
        dp[n-1][m-1] = 1;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i == n-1 && j == m-1)continue;
                if(grid[i][j] == 1)dp[i][j] = 0;
                else{
                    int rightWays = 0;
                    int bottomWays = 0;
                    
                    if(j+1<m){
                        rightWays = dp[i][j+1]%1000000007;
                    }
                    if(i+1<n){
                        bottomWays = dp[i+1][j]%1000000007;
                    }
                    
                    dp[i][j] = (rightWays+bottomWays);
                }
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends