//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        //sum of arr elements
        //sum of n numbers
        //sum of squares of arr elements
        //sum of squares of n numbers
        
        // let X be duplicate number and Y be missing number
        
        long long int sumArr = 0,sumN;
        long long int sumSqArr = 0,sumSqN;
        
        // sum of n natural numbers
        sumN = ((long long int)n*(long long int)(n+1))/2;
        
        // sum of squares of n natural numbers
        sumSqN = ((long long int)n*(long long int)(n+1)*(long long int)(2*n+1))/6;
        
        
        for(int i=0;i<n;i++){
            sumArr+=arr[i];
            sumSqArr+=(long long int)arr[i]*(long long int)arr[i];
        }
        
        //value of X-Y 
        long long int val1 =sumArr-sumN;
        
        // value of X+Y
        long long int val2 = sumSqArr-sumSqN;
        val2 = val2/val1;
        
        
        // this will contain the 
        long long int X = (val1+val2)/2;
        long long int Y = val2-X;
        
        vector<int>result;
        result.push_back(X);
        result.push_back(Y);
        
        return result;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends