//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:

    int firstOccurence(vector<int>arr,int low,int high){
        int mid = low + (high-low)/2;
        int firstOccuredIndex = high;
        while(low<=high){
            if(arr[mid] == 1){
                firstOccuredIndex = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
            mid = low + (high-low)/2;
        }
        return firstOccuredIndex;
    }
    
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int maxOnes = 0;
        int maxOnesIndice = -1;
        for(int i=0;i<n;i++){
          int total = m-firstOccurence(arr[i],0,m);
          if(total > maxOnes){
              maxOnes = total;
              maxOnesIndice = i;
          }
        }
        
        return maxOnesIndice;
	}



};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code 