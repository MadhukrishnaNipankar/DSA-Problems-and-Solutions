//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isPossible(  int mid,vector<int>& nums,int K){
        // dividing each number of nums by mid and adding 
      int result = 0;
        
        for(int i=0;i<nums.size();i++){
            result+=int(ceil(nums[i]*1.0/mid));
        }
        
        // cout<<mid<<" : "<<result<<endl;
        if(result<=K)return true;
        
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int K) {
        
       int maxNum = nums[0];
        // finding max number
        for(int i=0;i<nums.size();i++){
          maxNum = max(maxNum,nums[i]); 
        } 
        
        // finding the number using binary search for range 1 to maxNum
          int low = 1;
          int high = maxNum;
          int result = maxNum;
        
        
        while(low<=high){
            int mid = low + (high-low)/2;
              
              if(isPossible(mid,nums,K)){
                  result = min(maxNum,mid);
                  high = mid - 1;
              }
              else{
                  low = mid + 1;
              }
        }
        
        return result;
        
        
        /*
        Thinking :)
        1 2 5 9
        k = 6
        
        
        consider 9
        1 + 1 + 1 + 1 = 4
        4<= K(6)
        
        
        low = 1
        high = 9
        mid = 5
        
        
        1 + 1 + 1 + 2 = 5
        5<=k(6)
        
        
        1+4/2 = 2
        1 + 1 + 3 + 4 = 9
        9<k;
        
        1+2/2 = 1
        here low == high so stop
        */
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends