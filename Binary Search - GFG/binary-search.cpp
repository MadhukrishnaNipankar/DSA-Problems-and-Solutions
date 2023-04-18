//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int BS(int arr[],int low,int high,int target){
        if(low>high)return -1;
        
        int mid = low + (high-low)/2;
        
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid]>target){
            return BS(arr,low,mid-1,target);
        }
        else{
            return BS(arr,mid+1,high,target);
        }
    }
  
    int binarysearch(int arr[], int n, int k) {
        int low = 0,high = n-1,target=k;
        int searchedIndex =  BS(arr,low,high,target);
        return searchedIndex;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends