//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

        void bitManipulation(int num, int i) {
            // 1. Get ith bit
            bool ithBit = (num & (1 << (i - 1))) != 0;
            cout << ithBit << " ";
        
            // 2. Set ith bit
            num = num | (1 << (i - 1));
            cout << num << " ";
        
            // 3. Clear ith bit
            num = num & ~(1 << (i - 1));
            cout << num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends