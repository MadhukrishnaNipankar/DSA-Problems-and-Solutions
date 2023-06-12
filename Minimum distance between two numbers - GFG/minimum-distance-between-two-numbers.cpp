//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
       int xIndex = -1;
       int yIndex = -1;
       int difference = INT_MAX;
       
       for(int i=0;i<n;i++){
            if(a[i] == x){
                xIndex = i;
            }
            
            if(a[i] == y){
                yIndex = i;
            }
            
            if(xIndex > -1 && yIndex > -1){
                difference = min(difference,abs(yIndex-xIndex));
            }
       }
       
       
       if(xIndex== -1 || yIndex == -1)return -1;
       
       return difference;
       
       
     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends