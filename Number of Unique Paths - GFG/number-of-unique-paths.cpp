//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
      int help(int row,int col,int m,int n,vector<vector<int>>&dp){
            // if not inside boundaries
            if(row<0 || row>=m || col<0 || col>=n )return 0;
            
            if(row == m-1 && col == n-1){
                return 1;
            }
            if(dp[row][col] != -1)return dp[row][col];
            
           int rightPaths =  help(row,col+1,m,n,dp);
           int leftPaths =  help(row+1,col,m,n,dp);
           dp[row][col] = rightPaths+leftPaths;
           
           return dp[row][col];
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        int i=0,j=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
       
        return help(i,j,m,n,dp);
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends