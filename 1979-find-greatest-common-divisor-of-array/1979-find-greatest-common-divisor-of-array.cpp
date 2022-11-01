class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int min = nums[0], max = 0;
        // [2,5,6,9,10]
        
        //1] finding min and max
        for(int i = 0;i<n;i++){
            if(nums[i] < min)
                min = nums[i];     
            
            if(nums[i]> max)
                max = nums[i];           
        }
        
        //2] Finding GCD
        int GCD = 0;
        for(int i = 1;i<=min;i++){
            if(min%i == 0 && max%i == 0 && GCD<i){
                GCD = i;
            }
        }

        
        return GCD;
    }
};


/*
Approach:
1]Find the minimum and maximum in one iteration. Let them be mn and mx
2]Try all the numbers in the range [1, mn] and check the largest number which divides both of them.
*/