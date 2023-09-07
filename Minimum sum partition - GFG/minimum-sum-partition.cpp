//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  std::vector<std::vector<int>> memo;  // Memoization table

int diff(int i, int sum1, int sum2, int arr[], int n) {
    if (i == n) {
        return abs(sum1 - sum2);
    }

    // Check if the result for this subproblem is already calculated
    if (memo[i][sum1] != -1) {
        return memo[i][sum1];
    }

    // Calculate and store the result in the memo table
    int includeInSum1 = diff(i + 1, sum1 + arr[i], sum2, arr, n);
    int includeInSum2 = diff(i + 1, sum1, sum2 + arr[i], arr, n);

    memo[i][sum1] = min(includeInSum1, includeInSum2);

    return memo[i][sum1];
}

int minDifference(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Initialize the memoization table with -1
    memo.resize(n + 1, std::vector<int>(sum + 1, -1));

    return diff(0, 0, 0, arr, n);
}

};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends