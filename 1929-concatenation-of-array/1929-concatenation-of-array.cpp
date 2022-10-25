class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        
        int i = 0;
        while(i<n){
            ans.at(i+n) = ans.at(i) = nums[i];
            i++;
        }
        return ans;
    }
};