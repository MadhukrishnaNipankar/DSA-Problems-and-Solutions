//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int search(int A[], int l, int h, int key){
        int low = l,high = h;
      
        while (low <= high) { //<--- step 2
    int mid = (low + high) >> 1; //<----step 3
    if (A[mid] == key)
      return mid; // <---step 4

    if (A[low] <= A[mid]) { //<---step 5
      if (A[low] <= key && A[mid] >= key)
        high = mid - 1; //<---step 6 
      else
        low = mid + 1; //<---step 7
    } else { //<---step 7
      if (A[mid] <= key && key <= A[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
        
  
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends