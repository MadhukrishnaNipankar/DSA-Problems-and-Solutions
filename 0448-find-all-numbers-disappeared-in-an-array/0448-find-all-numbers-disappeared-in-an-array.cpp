class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {       
        vector<int> disappearedNums;
        
        for(int i = 0;i<nums.size();i++){
            int currentNumber = abs(nums[i]);
            int markingIndex = currentNumber - 1;

            //negating the element
            if(nums[markingIndex]>0)
            nums[markingIndex] *=-1;    
        }
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0)
                disappearedNums.push_back(i+1);
        }

        return disappearedNums; 
    }
};