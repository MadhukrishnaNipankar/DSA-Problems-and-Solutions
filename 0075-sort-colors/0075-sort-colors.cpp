class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0, ones = 0, twos = 0;
        //counting 0's, 1's and 2's
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroes++;
            }
            else if(nums[i] == 1){
                ones++;
            }
            else if(nums[i] == 2){
                twos++;
            }
        }
        
        cout<<"zero : "<<zeroes;        cout<<"two : "<<twos;
        cout<<"one : "<<ones;

        
        
        // Modifying the array 
        int i = 0;
            for(;i<zeroes;i++){ 
                nums[i] = 0;
            }
            
            for(;i<zeroes+ones;i++){
                nums[i] = 1;
            }
        
            for(;i<zeroes+ones+twos;i++){
                nums[i] = 2;
            }
            

    }
};