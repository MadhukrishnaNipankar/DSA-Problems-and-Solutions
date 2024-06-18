class Solution {
public:
    //O(N*N) -----> Time Limit Exceeded     
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int maxi = 0;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 maxi = max(maxi,prices[j]-prices[i]);
//             }
//         }
        
//         return maxi;
//     }
    
    
    
      int maxProfit(vector<int>& prices) {
          int n = prices.size();
          
          int minSoFar = prices[0];
          int maxi = 0;
          
          for(int i=0;i<n;i++){
              maxi = max(maxi,prices[i]-minSoFar);
              minSoFar = min(minSoFar,prices[i]);
          }
          return maxi;
                
                    
      }
};