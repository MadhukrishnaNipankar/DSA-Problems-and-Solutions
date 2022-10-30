class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> indices;
        
        //sorting the array 
        sort(nums.begin(), nums.end());
        
        //finding the indices
        for(int i = 0;i<n;i++){
            if(nums[i]>target){
                break;
            }
            if(nums[i] == target){
                indices.push_back(i);
            }
        }
        
        return indices;
        
    }
};