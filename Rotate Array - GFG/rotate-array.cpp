//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    
    void reverseArray(int arr[],int low,int high){
        while(low<=high){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }

    void rotateArr(int arr[], int d, int n){
    // Madhukrishna's Algorithm
        if(n==1) return;
        
         d = d%n;
    //     int temp = arr[n-1];
    //     int tempPrev = 0;
        
    
       
    //     // OOOO bhai kuch kar yarrr
    //   while(d){
    //       int i = n-1;
    //         while(i>=0){
    //         if(i == 0){
    //             arr[n-1] = temp;
    //         }
    //         else{
    //             // cout<<"temp : "<<temp<<"  , tempPrev :"<<tempPrev<<endl;
    //              tempPrev = arr[i-1];
    //              arr[i-1] = temp;
    //              temp = tempPrev;
    //         }
            
        
    //             i--;
    //         }
    //         d--;
    //   }
    
    

    
    
    
    
    reverseArray(arr,0,n-1);
    //   reverseArray(arr,0,16);
    //     reverseArray(arr,17,n-1);
    
    
    reverseArray(arr,0,n-d-1);
    reverseArray(arr,n-d,n-1);
    
    

    
    
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends