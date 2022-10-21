class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       vector<int> ans;
        //1] xor all the array elements
        int allXor = 0;
        for(int i=0;i<nums.size();i++){
            allXor^=nums[i];
        }
        
        //2] finding the position of the right most set bit in the result
        int pos = 0; int temp = allXor;
        for(;pos<32;pos++){
            if(temp&1){
                break;
            }
            temp = temp>>1;
        }
        
        //3] traversing to all the array elements again and xoring only the elements with set bit at same position as allXor. 
        int first = 0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]>>pos) & 1){
                first^=nums[i];
            }
        }
        ans.push_back(first);
        
        // 4]to get the second element, we do this. because allXor also contains 'first' number. so they both cancel out each other and we get second
        int second = first^allXor;
        ans.push_back(second);
        
        return ans;
    }
};