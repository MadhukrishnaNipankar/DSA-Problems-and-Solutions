//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int count = 0;
    
    void merge(vector<int>&arr,int low,int mid,int high){
        int i = low, j = mid+1;
        int temp[high-low+1];
        int k = 0;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp[k] = arr[i];
                i++;
                k++;
            }
            else{
                temp[k] = arr[j];
                j++;
                k++;
            }
        }
        
        
        
        while(i<=mid){
            temp[k] = arr[i];
            i++;
            k++;
        }
        
         while(j<=high){
            temp[k] = arr[j];
            j++;
            k++;
        }
        
        
        for(int i=0;i<high-low+1;i++){
            arr[i+low] = temp[i]; 
        }
        
    }
    
    void countPairs(vector<int>&arr, int low, int mid, int high){
        int right = mid+1;
        for(int i=low;i<=mid;i++){
         
            while(right <= high && arr[i] > 2*arr[right])right++;
            
            count+= (right-(mid+1));
        }
    }
        
    void mergeSort(vector<int>&arr,int low,int high){
        if(low>=high)return;
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
    }
   
   
    
   
    int countRevPairs(int n, vector<int> arr) {
        mergeSort(arr,0,n-1);
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends