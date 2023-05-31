//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int>hash(pow(10,5),0);
        vector<int>duplicates;
        
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }
        
        for(int i=0;i<hash.size();i++){
            if(hash[i] > 1)duplicates.push_back(i);
        }
        
        if(duplicates.size() == 0)duplicates.push_back(-1);
        return duplicates;
        
    }
    
    
    /*
    Thinking :)
    
    2 3 1 2 3 
    0 1 2 3 4
    
    
   
    
    */
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends