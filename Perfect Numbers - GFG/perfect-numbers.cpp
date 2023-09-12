//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int isPerfectNumber(long long N) {
        // code here
        if (N <= 1) return 0; // 0 and 1 aren't perfect numbers

        long long sum = 1; // starting with 1 as it's a factor of every number
    
        for (long long i = 2; i <=sqrt(N); i++) {
            // If 'i' is a divisor of 'N'
            if (N % i == 0) {
                sum += i;
                if (i != (N / i)) sum += (N / i);
            }
        }
    
        return sum == N; // If the sum of factors equals N, it's perfect
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends