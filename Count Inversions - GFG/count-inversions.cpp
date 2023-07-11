//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count = 0;
    
    void merge(long long arr[],long long low,long long mid,long long high){
        // 2 3 5 6 
        //2 2 4 4 8
        
        long long i = low, j = mid+1;
        long long temp[high-low+1];
        long long k = 0;
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
                count+=(mid-i+1);
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
    
        
    void mergeSort(long long arr[],long long low,long long high){
        if(low>=high)return;
        long long mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends