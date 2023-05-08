//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
  
    int findOnce(int arr[], int n)
    {
        if(n == 1)return arr[0];
        
        if(arr[0]!=arr[1])return arr[0];
        if(arr[n-1]!=arr[n-2])return arr[n-1];
        
        
        
        int low = 0;
        int high = n-1;
     
        
        while(low<=high){
          int mid = low + (high-low)/2;
           
          if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
              return arr[mid];
          } 
          else if(arr[mid] == arr[mid-1]){
            //   low to mid elements count
            int lc = mid-low+1;
            
            if(lc%2 == 0){
                low = mid+1;
            }
            else{
                high = mid-2;
            }
          }
          else if(arr[mid] == arr[mid+1]){
             //mid to high elements count
             int rc = high-mid+1;
             
             if(rc%2 == 0){
                 high = mid-1;
             }
             else{
                 low = mid+2;
             }
          }
          
          
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends