class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>hash;
        int n = nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
            if(hash[nums[i]] == 2)return true;
        }
        return false;
    }
};