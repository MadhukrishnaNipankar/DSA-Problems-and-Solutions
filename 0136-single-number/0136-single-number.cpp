class Solution {
public:
    /*
    logic:
    
    number XOR 0 = number
    number XOR number = 0
    
    
    so if we do number XOR number, all the duplicated will get removed. 
    and at some point, 0 XOR number would be the answer. 
    */
    
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int i = 0;i<nums.size();i++){
            answer = answer^nums[i];
        }
        return answer;
    }
};