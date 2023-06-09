//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
      int left = 0,right = 0;
      int flippedZeroes = 0;
      int max1s = 0;
      while(right<n){
          if(arr[right] == 0){
            flippedZeroes++;
          }
          while(flippedZeroes > m){
                  if(arr[left] == 0)
                  {
                      flippedZeroes--;
                  }
                  left++;
              }
              
           max1s = max(max1s,right-left+1);
          
          right++;
      }
      
      return max1s;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends