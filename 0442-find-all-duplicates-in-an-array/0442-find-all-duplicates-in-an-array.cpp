class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
        for(int i = 0;i<nums.size();i++){
            int currentNumber = abs(nums[i]);
            int markingIndex = currentNumber - 1;

            //negating the element
            nums[markingIndex] *=-1;
            
            //if the number is positive,after multiplying it with -1, means double negation had happened, that means it is duplicate number
            if(nums[markingIndex] > 0){
                duplicates.push_back(currentNumber);
            }
        }

        return duplicates;
    }
};