//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
// memoization
//   bool help(int i, vector<int>& arr, int sum, vector<vector<int>>& dp) {
//     // Base cases
//     if (sum < 0 || i >= arr.size()) {
//         return false;
//     }
//     if (sum == 0) {
//         return true;
//     }

//     // Check if the subproblem is already solved
//     if (dp[i][sum] != -1) {
//         return dp[i][sum];
//     }

//     // Try including the current element
//     bool includeCurrent = help(i + 1, arr, sum - arr[i], dp);

//     // Try excluding the current element
//     bool excludeCurrent = help(i + 1, arr, sum, dp);

//     // Update dp table and return the result
//     dp[i][sum] = includeCurrent || excludeCurrent;
//     return dp[i][sum];
// }

    bool isSubsetSum(vector<int> arr, int sum) {
        // memoization code
        // int N = arr.size();
        // int M = sum + 1;
        // vector<vector<int>> dp(N, vector<int>(M, -1));
    
        // return help(0, arr, sum, dp);
        
        // tabulation
            int N = arr.size();
            vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));
        
            // Base case: If the sum is 0, there's always an empty subset.
            for (int i = 0; i <= N; i++) {
                dp[i][0] = true;
            }
        
            // Fill the dp table
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= sum; j++) {
                    // If the current element is greater than the current sum, exclude it.
                    if (arr[i - 1] > j) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        // Otherwise, include or exclude the current element.
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                    }
                }
            }
        
            // The result is stored in dp[N][sum]
            return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends