//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    {
         unordered_map<int, int> freqMap; // To store element frequencies

    // Count the frequency of each element in the array
    for (int i = 0; i < n; ++i) {
        freqMap[arr[i]]++;
    }

    // Iterate through the array to find the first non-repeating element
    for (int i = 0; i < n; ++i) {
        if (freqMap[arr[i]] == 1) {
            return arr[i]; // Found the first non-repeating element
        }
    }

    return 0; // If no non-repeating element found
    } 
  
};


//{ Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}

// } Driver Code Ends