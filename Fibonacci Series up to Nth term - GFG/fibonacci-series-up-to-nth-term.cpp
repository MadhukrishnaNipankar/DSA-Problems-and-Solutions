//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<long long> Series(int N) {
 
        vector<long long> ans;
        ans.push_back(0);
        ans.push_back(1);
        for(int i = 2; i<=N; i++){
            long long newNu = ans[i-1] + ans[i-2];
            ans.push_back(newNu);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<long long> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends