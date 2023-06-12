//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int majorityElement(int nums[], int size)
    {
       int count = 0;
       int candidate;

       for(int i = 0;i<size;i++){
            if(count == 0){
                candidate = nums[i];
            }

            if(nums[i] == candidate)
                count++;
            else
                count--;
       }
     
     int actualCount = 0;
     for(int i=0;i<size;i++){
         if(nums[i] == candidate){
             actualCount++;
         }
     }
    
    int nBy2 = size/2;
    if(actualCount > nBy2){
       return candidate;
    }
     
     
    return -1;
         
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends