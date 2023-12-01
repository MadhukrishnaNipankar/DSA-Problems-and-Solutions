//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
   //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
       vector<int>result;
       int start = 0;
       int end = 0;
       long long currentSum = arr[0];
       
       if(s == 0){
           for(int i=0;i<n;i++){
               if(arr[i] == 0){
                      result.push_back(i+1);
                      result.push_back(i+1);
                      return result;
               }
           }
           
           result.push_back(-1);
           return result;
       }
   
       
       while(end<n){
             while(currentSum > s && start<=end){
               currentSum-=arr[start];
               start++;
             }
             
              if(currentSum == s){
               result.push_back(start+1);
               result.push_back(end+1);
               return result;
              }
              
            end++;
           
            if(end<n)
               currentSum+=arr[end];
  
       }

      //control reaches here, that means we have not found such solution
      result.push_back(-1);
      return result;
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends