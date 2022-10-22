class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size() == 1)return nums;
        int i = 1;
        while(i<nums.size()){
            nums [i] = nums[i-1] + nums[i];
            i++;
        }
        return nums;
    }
};