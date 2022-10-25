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