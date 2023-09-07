//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// memoization
    // int help(int i,int temp,int sum,int N,int arr[],vector<vector<int>>&dp){
    //     if(sum == temp)return 1;
    //     if(temp > sum)return 0;
        
    //     if(i>=N)return 0;
        
    //     // dp step
    //     if(dp[i][sum]!= -1)return dp[i][sum];
        
    //     // pick this element
    //     temp+=arr[i];
    //     int pick = help(i+1,temp,sum-arr[i],N,arr,dp);
    //     temp-=arr[i];
        
    //     // don't pick this element
    //     int notPick = help(i+1,temp,sum,N,arr,dp);
        
    //     return dp[i][sum] = pick || notPick;
    // }
    int equalPartition(int N, int arr[])
    {
        // memoization code
        // int sum = 0;
        // for(int i=0;i<N;i++){
        //     sum+=arr[i];
        // }
        
        // vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        // int temp = 0;
        // return help(0,temp,sum,N,arr,dp);
        
        // tabulation code
            int sum = 0;
            for (int i = 0; i < N; i++) {
                sum += arr[i];
            }
            
            // If the sum is odd, it can't be divided into two equal parts
            if (sum % 2 != 0) {
                return 0;
            }
            
            sum /= 2; // We only need to find if half of the sum is achievable
            vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));
            
            // Base case
            for (int i = 0; i <= N; i++) {
                dp[i][0] = 1;
            }
            
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= sum; j++) {
                    if (j >= arr[i - 1]) {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        
            return dp[N][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends