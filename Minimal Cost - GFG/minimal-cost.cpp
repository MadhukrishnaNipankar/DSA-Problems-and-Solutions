//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   Tabulation
     int minimizeCost(vector<int>& height, int n, int k) {
     vector<int>dp(n+1,-1);
     dp[0]=0;
     for(int i=1;i<n;i++){
         int ministeps=INT_MAX;
         for(int j=1;j<=k;j++){
             if(i-j>=0) {
                 int jump=dp[i-j]+abs(height[i]-height[i-j]);
                ministeps=min(ministeps,jump);
             }
         }
         dp[i]=ministeps;
     }
     return dp[n-1];
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