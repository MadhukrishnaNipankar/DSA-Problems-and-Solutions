//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {

	   
	   int temp[n];
	   int i = 0;
	   int positivePtr = 0, negativePtr = 0;

/*
-36 -9 -92 -87 -43 -44    
*/
        
	   while(positivePtr<n || negativePtr<n){
	       //take positive number
    	    
    	            while(positivePtr<n && arr[positivePtr]<0){
    	                positivePtr++;
    	            }
    	       
    	            if(positivePtr<n){
    	                temp[i]=arr[positivePtr];
        	            positivePtr++;
        	            i++;
    	            }
        	      
    	     
	       
	       //take negative number
	        
	           while(negativePtr<n && arr[negativePtr]>=0){
	                negativePtr++;
	            }
	            
	           if(negativePtr<n){
	            temp[i]=arr[negativePtr];
	            negativePtr++;
	            i++;
	          }
	   }
	 
	   for(int j=0;j<n;j++){
	       arr[j] = temp[j];
	   }
	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends