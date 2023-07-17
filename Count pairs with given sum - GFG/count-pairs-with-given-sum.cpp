//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // hashing 
        map<int,int>hash;
        int pairCount = 0;
        
        for(int i=0;i<n;i++){
            int diff = k-arr[i];
            
            if(hash[diff]>0){
                pairCount+=hash[diff];
            }
            
            hash[arr[i]]++;
            
          
        }
        
    
       
        
        return pairCount;
        /*
        
        1 1 1 1
        
        hashmap
        1 4
        
        
        */
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends