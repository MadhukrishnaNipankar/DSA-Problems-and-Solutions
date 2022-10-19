class Solution {
public:
    
    int missingNumber(vector<int>& nums) {
        int sum = 0, arraySum = 0;
        //calculating sum of numbers from 1 to n
        for(int i = 1;i<=nums.size();i++){
            sum = sum + i;
        }
        
        //calculating sum of array elements
        for(int i = 0;i<nums.size();i++){
            arraySum = arraySum + nums[i];
        }
        
        
        return sum-arraySum;
    }
};