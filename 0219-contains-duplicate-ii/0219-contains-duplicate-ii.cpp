class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(hash[nums[i]]){
                if(abs(hash[nums[i]]-1-i)<=k)return true;
            }
            hash[nums[i]] = i+1; 
        }
        
        return false;
    }
};