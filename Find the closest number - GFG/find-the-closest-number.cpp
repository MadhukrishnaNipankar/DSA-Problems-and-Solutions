//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int target) 
    { 
       int minimumDistance = abs(target-arr[0]);
       int currentNumber = arr[0];
       
       for(int i=0;i<n;i++){
           if(abs(target-arr[i]) < minimumDistance)
           {
               minimumDistance = abs(target-arr[i]);
               currentNumber = arr[i];
           }
           else if(abs(target-arr[i]) == minimumDistance){
               currentNumber = max(currentNumber,arr[i]);
           }
       }
       
       return currentNumber;
    } 
    
    
    
    /*
     1 7 9 10 5
    target  = 3
    
    
    */
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends