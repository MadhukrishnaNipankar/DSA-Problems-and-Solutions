//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int helper(vector<int>& height, int n, vector<int>& dp,int k){
        if(n<=0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int minCost = INT_MAX;
        for(int i=1;i<=k;i++){
         if(n-i>= 0)
          minCost = min(helper(height, n-i, dp,k) + abs(height[n]- height[n-i]),minCost);
        }
        
        dp[n] = minCost;
       
        return dp[n];
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, -1);
        return helper(height, n-1, dp,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends