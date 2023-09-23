//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        // edge case:
        if(n == 1)return 1;
        
        int leftPtr = 0;
        int rightPtr = n-1;
        
        long long int leftSummation = a[0],rightSummation = a[n-1];
        
        
        
        while(leftPtr<rightPtr){
            if(leftSummation < rightSummation){
                leftPtr++;
                leftSummation+=a[leftPtr];
            }
            else {
                rightPtr--;
                rightSummation+=a[rightPtr];
            }
        }
        
       
    //   cout<<a[leftPtr]<<" -> a[leftPtr]"<<endl;
    //           cout<<a[rightPtr]<<" -> a[rightPtr]"<<endl;
    //     cout<<leftPtr<<" : "<<leftSummation<<endl;
    //      cout<<rightPtr<<" : "<<rightSummation<<endl;
        if(leftSummation == rightSummation)return leftPtr+1;
        else return -1;
        
        
        return leftPtr+1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends