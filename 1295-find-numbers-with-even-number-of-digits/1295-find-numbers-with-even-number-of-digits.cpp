class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenDigits = 0;
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
             int j = nums[i];
             
            //counting number of digits in nums[i]
            int numOfDigits = 0;
             while(j!=0){
                 numOfDigits++;
                 j/=10;
             }
            
            if(numOfDigits%2 == 0){
                evenDigits++;
            }
            
        }
        
        return evenDigits;
    }
};

//1] Counting Number of Digits for each Number
//2] If it is even, increasing the count
//3] Returning the count