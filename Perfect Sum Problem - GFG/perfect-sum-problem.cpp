//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
  int t[1001][1001];
    int mod = 1e9+7;
    
    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    int solve(int arr[],int n, int sum){
        if(sum==0) return 1;
        else if(sum<0 || n<=0) return 0;
        else if(t[n][sum]!=-1) return t[n][sum]%mod;
        else if(arr[n-1]<=sum && arr[n-1]!=0) t[n][sum] = solve(arr,n-1,sum-arr[n-1]) + solve(arr,n-1,sum);
        else t[n][sum] = solve(arr,n-1,sum);
        return t[n][sum]%mod;
    }
    
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        int zero=0;
        for(int i=0; i<n; i++){
            if(arr[i]==0) zero++;
        }
        int ans=solve(arr,n,sum);
        return (pow(2,zero))*(ans%mod);
    } 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends