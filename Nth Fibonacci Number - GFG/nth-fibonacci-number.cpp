//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   
    int nthFibonacci(int n){
   if (n <= 0)
        return 0;

    // Initialize an array to store Fibonacci numbers
    int fib_nums[n + 1];
    
    // Base cases
    fib_nums[0] = 0;
    fib_nums[1] = 1;
    
    // Calculate Fibonacci numbers up to the nth position
    for (int i = 2; i <= n; i++) {
        fib_nums[i] = (fib_nums[i - 1] + fib_nums[i - 2]) % 1000000007;
    }
    
    return fib_nums[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends