class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
 int sum  = 0, ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            ans = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    ans ++;
                }
            }
            
            if(ans < 2) {
                    sum = sum + nums[i];
                }
        }
        
        return sum;
};
    
};