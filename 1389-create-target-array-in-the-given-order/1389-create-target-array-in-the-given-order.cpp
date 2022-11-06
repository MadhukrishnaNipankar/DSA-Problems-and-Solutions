class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
               vector<int> TARGET;
                 for(int i=0;i<index.size();++i)
                         TARGET.insert(TARGET.begin()+index[i],nums[i]);
                return TARGET;
    }
};