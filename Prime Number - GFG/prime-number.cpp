//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
  int isPrime(int n) {
    // Handle special cases where n is not a prime number
    if (n <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // n is divisible by i, so it's not prime
        }
    }
    
    return 1; // If no divisors are found, n is prime
}
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends