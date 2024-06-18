class Solution {
public:
   // //bruteforce approach  O(nsquare)   
   //  vector<int> twoSum(vector<int>& nums, int target) {
   //      int n = nums.size();
   //      for(int i=0;i<n-1;i++){
   //          for(int j=i+1;j<n;j++){
   //              if(nums[i]+nums[j] == target)return {i,j};
   //          }
   //      }
   //   return {};
   //  }
    
    //better 2 pointer approach  O(nlogn + n)     
//  vector<int> twoSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     vector<pair<int, int>> numIndexPairs;

//     // Create a vector of pairs (value, index)
//     for (int i = 0; i < n; i++) {
//         numIndexPairs.push_back({nums[i], i});
//     }

//     // Sort the pairs based on the values
//     sort(numIndexPairs.begin(), numIndexPairs.end());

//     int i = 0, j = n - 1;
//     while (i < j) {
//         int sum = numIndexPairs[i].first + numIndexPairs[j].first;
//         if (sum == target) {
//             // Return a vector of the original indices
//             return {numIndexPairs[i].second, numIndexPairs[j].second};
//         } else if (sum > target) {
//             j--;
//         } else {
//             i++;
//         }
//     }

//     // Return an empty vector if no solution is found
//     return {};
// }
    
    
    // optimal O(n)using hashmap .O(n) one pass solution
    vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            unordered_map<int,int>hash;
            for(int i=0;i<n;i++){
                   if(hash[target-nums[i]])return {i,hash[target-nums[i]]-1};
                   
                   hash[nums[i]] = i+1; 
            }
        
        return {};

    }
   

};