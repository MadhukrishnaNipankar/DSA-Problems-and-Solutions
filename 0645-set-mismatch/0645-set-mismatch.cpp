class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i = 1,duplicateNum;
        //1] finding duplicate
        while(i<nums.size()){
            if(nums[i-1] == nums[i])
            {
                duplicateNum = nums[i];
                break;
            }
            i++;
        }
        ans.push_back(duplicateNum);
        
        //2] xoring 1 - n numbers with all array elements
        int Xor = 0;
        i = 1;
        while(i<=nums.size()){
            Xor = Xor^nums[i-1]^i;
            i++;
        }
        
        //3] Finding the missing element
        int missingElement = Xor^duplicateNum;
        ans.push_back(missingElement);
        
        return ans;
    }
};