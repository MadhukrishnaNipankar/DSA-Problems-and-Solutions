//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:

    int firstRepeated(int arr[], int n) {
      vector<int>hash(pow(10,6),0);
       
       
      
       
       for(int i=0;i<n;i++){
        // cout<<arr[i]<<" : "<<hash[arr[i]]<<endl;
        hash[arr[i]] = hash[arr[i]] +  1;
       }
       
       for(int i=0;i<n;i++){
            if(hash[arr[i]] > 1)return i+1;
       }
       
       
       return -1;
       
    }
    
    
    /*
    Thinking :)
    
    1 5 3 4 3 5 6 
    
    1 1
    5 2
    3 3
    4 4
    3 5
    6 7
    */
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends