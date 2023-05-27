//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int leftElement(int arr[], int n) {
      sort(arr, arr + n);
      //7, 8, 3, 4, 2, 9, 5}
    //   2 3 4 5 7 8 9 
    int low = 0;
    int  high = n-1;
    int mid = (low + high)/2;
    return arr[mid];
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.leftElement(a, n) << endl;
    }
}

// } Driver Code Ends