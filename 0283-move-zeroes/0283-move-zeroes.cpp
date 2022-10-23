class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;
      
        while(i<nums.size()-1){
            if(nums[i] == 0){
                while(nums[j] == 0 && j<nums.size()-1){
                    j++;
                }
                swap(nums[i], nums[j]);
            }
            i++;
            j = i+1;
        }
        
    }
};