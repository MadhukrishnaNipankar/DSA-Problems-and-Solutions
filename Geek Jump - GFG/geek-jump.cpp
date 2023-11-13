//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
    int minimumEnergy(vector<int>& height, int n) {
            vector<int>tab(n+1,0);
            tab[0] = 0;
            
            for(int i=1;i<n;i++){
                int left = tab[i-1] + abs(height[i-1] - height[i]);
                
                int right = INT_MAX;
                
                if(i>1)
                right = tab[i-2] + abs(height[i-2] - height[i]);
                
                tab[i] = min(left,right);
            }
            
            return tab[n-1];
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends