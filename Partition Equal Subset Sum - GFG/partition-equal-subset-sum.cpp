//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int help(int i,int temp,int sum,int N,int arr[],vector<vector<int>>&dp){
        if(sum == temp)return 1;
        if(temp > sum)return 0;
        
        if(i>=N)return 0;
        
        // dp step
        if(dp[i][sum]!= -1)return dp[i][sum];
        
        // pick this element
        temp+=arr[i];
        int pick = help(i+1,temp,sum-arr[i],N,arr,dp);
        temp-=arr[i];
        
        // don't pick this element
        int notPick = help(i+1,temp,sum,N,arr,dp);
        
        return dp[i][sum] = pick || notPick;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        int temp = 0;
        return help(0,temp,sum,N,arr,dp);
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