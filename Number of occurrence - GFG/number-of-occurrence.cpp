//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
int firstOccurence(int arr[],int low,int high,int target){
	    int mid = low+(high-low)/2;
	    int firstOccurenceIndex = -1;
	    while(low<=high){
	        if(arr[mid] == target){
	            firstOccurenceIndex = mid;
	            high = mid-1;
	        }
	        else if(arr[mid] > target){
	            high = mid - 1;
	        }
	        else{
	            low = mid + 1;
	        }
	        
	        mid = low + (high-low)/2;
	    }
	    return firstOccurenceIndex;
	}	
		
		
	int lastOccurence(int arr[],int low,int high,int target){
	    int mid = low+(high-low)/2;
	    int lastOccurenceIndex = -1;
	    while(low<=high){
	        if(arr[mid] == target){
	            lastOccurenceIndex = mid;
	             low = mid + 1;
	        }
	        else if(arr[mid] > target){
	            high = mid - 1;
	        }
	        else{
	            low = mid + 1;
	        }
	        
	        mid = low + (high-low)/2;
	    }
	    return lastOccurenceIndex;
	}
		
		
	int count(int arr[], int n, int x) {
	    int firstOccurenceIndex = firstOccurence(arr,0,n-1,x);
	    if(firstOccurenceIndex == -1)return 0;
	    
	    int lastOccurenceIndex = lastOccurence(arr,0,n-1,x);
	    int count = lastOccurenceIndex - firstOccurenceIndex + 1;
	    return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends