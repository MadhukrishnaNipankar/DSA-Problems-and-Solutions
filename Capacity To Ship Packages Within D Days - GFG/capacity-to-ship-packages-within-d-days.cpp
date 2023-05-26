//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPossible(int arr[],int N,int D,int mid){
        int capacity = 0;
        int requiredDays = 1; 
        for(int i=0;i<N;i++){
             capacity+=arr[i];
            
             if(capacity > mid){
                 requiredDays++;
                 capacity = arr[i];
             }
        }
       
        if(requiredDays>D){
            return false;
        }
      
        return true;
         
    }
  
    int leastWeightCapacity(int arr[], int N, int D) {
        int maxWeight  = arr[0];
        // finding maximum Weight
        for(int i=0;i<N;i++){
            maxWeight = max(maxWeight,arr[i]); 
        }
        
        int sumOfAllWeights = 0;
        // finding the sum of all weights
        for(int i=0;i<N;i++){
            sumOfAllWeights+=arr[i];
        }
        
        
        int low = maxWeight;
        int high = sumOfAllWeights;
        int minimumCapacity = INT_MAX;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(arr,N,D,mid)){
                minimumCapacity = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        
     return minimumCapacity;
        
    }
    
    /*
    Thinking : )
    
    
    observtion:
   1] if i am given 6 days for 6 weight, my minimum capacity would be the max Weight in that array
    
   2] if i am given 1 day for 6 weights, my minimum capacity would be the sum of Weights of the array    
    
    i.e low = max of all the given weights
        high = sum of all the given weights
    
    
    
    
    
    
    */
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends