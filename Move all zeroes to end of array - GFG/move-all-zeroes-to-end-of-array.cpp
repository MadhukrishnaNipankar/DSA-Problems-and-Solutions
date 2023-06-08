//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
        int i = 0;
        int j = 0;
        
        while(j<n){
            
        //   finding a zero
          while(arr[i]!=0){
              i++;
              j++;
          }
          
        //finding a non zero number
          while(arr[j]==0){
              j++;
              if(j>=n)return;
          }
         
          swap(arr[i],arr[j]);
          i++;
          j++;
        }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends