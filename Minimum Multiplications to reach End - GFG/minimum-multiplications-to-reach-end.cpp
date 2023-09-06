//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> dist(100000,1e9);
        dist[start]=0;
        int mod=100000;
        if(start==end)
        {
            return 0;
        }
        while(!q.empty())
        {
            int nd=q.front().first;
            int stp=q.front().second;
            q.pop();
            for(auto i:arr)
            {
                int n=(nd*i)%mod;
                if(stp+1<dist[n])
                {
                    dist[n]=stp+1;
                     if(n==end)
            {
                return stp+1;
            }
                    q.push({n,stp+1});
                }
            }
        }
        return -1;
    }

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends