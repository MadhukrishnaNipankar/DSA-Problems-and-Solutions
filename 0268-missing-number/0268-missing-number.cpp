class Solution {
public:
    
    int missingNumber(vector<int>& nums) {
        int sum = 0, arraySum = 0;
        //calculating sum of numbers from 1 to n
        for(int i = 1;i<=nums.size();i++){
            sum = sum + i;
        }
        
        //calculating sum of array elements
        for(int i = 0;i<nums.size();i++){
            arraySum = arraySum + nums[i];
        }
        
        int missingNumber = sum - arraySum;
        return missingNumber;
    }
};

/*
Approach: 
 -> suppose, our array is [3,0,1].
    so, we know that size of array is 3.
    so if we calculate 1+2+3 which is 6 --- (1)
    
    and then calculate the sum of array i.e 3+0+1 , which is 4 --- (2)
    
    and then subtract (2) from (1), i.e  6-4 = 2.
    we get the missing number
 
*/