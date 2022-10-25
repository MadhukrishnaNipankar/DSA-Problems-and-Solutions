
//o(n) space complexity
/*
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        
        while(i<n){
            ans.at(i) = nums[nums[i]];
            i++;
        }
        
        
        return ans;
    }
};

*/


//o(1) space complexity
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        while(i<n){
            nums.at(i) = nums[i] + ( n * (nums[nums[i]]%n));
            i++;
        }
        
         i = 0;
         while(i<n){
            nums.at(i) = nums.at(i)/n;
            i++;
        }
        
        
        return nums;
    }
};
