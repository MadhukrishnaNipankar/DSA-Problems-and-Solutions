//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int requiredHours(int speed,int N,vector<int>&piles){
        int time = 0;
         for(int i=0;i<N;i++){
            if(piles[i]<=speed){
                time+=1;
            }
            else{
                time+=int(ceil(piles[i]*1.0/speed));
            }
            
         }
        return time;   
     }
  
    int Solve(int N, vector<int>& piles, int H) {
        int maxPile = INT_MIN;
        // Search Pile with max bananas
        for(int i=0;i<N;i++){
            maxPile = max(maxPile,piles[i]);
        }
        
        // Applying Binary Search
         int low = 0,high = maxPile;
         int minimumSpeed = INT_MAX;
         
        while(low<=high){
            int mid =(low + high)/2;
          
            if(requiredHours(mid,N,piles) <= H){
                minimumSpeed = min(minimumSpeed,mid);
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
            
            
        }
        
        return minimumSpeed;
    }
    
    
    /*
    Thinking :)
    
    3 6 7 11
    
    low = 0
    high = 11
    mid = 5
    
    iterate through piles array 
    ceil(3/5)+ceil(6/5)+ceil(7/5)+ceil(11/5)
    1 + 2 + 2 + 3 = 8
    
    store 8 as minSpeed;
    
    
    search in the range 0 to 4
    mid = 2
    iterate through piles array 
    ceil(3/2)+ceil(6/2)+ceil(7/2)+ceil(11/2)
    2 + 3 + 4 + 6 = 15
    
    
    dont store 15
    
    
    
    search in the range 3 to 4
    mid = 3
    iterate through piles array 
    ceil(3/3)+ceil(6/3)+ceil(7/3)+ceil(11/3)
    1 + 2 + 3 + 4 = 10
    
    
    dont store 10 as it is greater than min
    
    search in the range 4 to 4
    mid = 4
    iterate through piles array 
    ceil(3/4)+ceil(6/4)+ceil(7/4)+ceil(11/4)
    1 + 2 + 2 + 3 = 8
    
    
    
    1] Search Maximum Number
    2] Apply Binary Search from 0 to maxPile.
    
    
    */
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends