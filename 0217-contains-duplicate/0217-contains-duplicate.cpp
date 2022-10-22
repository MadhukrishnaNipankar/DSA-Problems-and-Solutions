class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //1] Sort the array
         sort(nums.begin(), nums.end());
         
        //2] check if the adjacent elements are equal. 
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};