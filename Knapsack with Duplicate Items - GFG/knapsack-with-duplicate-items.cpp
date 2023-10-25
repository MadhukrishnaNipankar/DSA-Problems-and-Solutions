//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int help(int index,int weight,int val[],int wt[],vector<vector<int>>&dp){
        // Base Case
        if(index == 0){
            return ((int)(weight/wt[0])*val[0]);
        }
        
        if(dp[index][weight]!= -1)return dp[index][weight];
        
        // Not Pick
        int notPick = 0 + help(index-1,weight,val,wt,dp);
        
        
        int pick = INT_MIN;
        // Pick
        if(wt[index] <= weight){
            pick = val[index] + help(index,weight-wt[index],val,wt,dp);
        }
        
        return dp[index][weight] = max(pick,notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
       vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
       return help(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends