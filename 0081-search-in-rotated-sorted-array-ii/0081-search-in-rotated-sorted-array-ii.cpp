class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(nums[mid] == target)return true;
            
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
                

            if(nums[low]<=nums[mid]){
    	        //this part is sorted
                if(target>=nums[low] && target<nums[mid]){
                    //if the element lies in the range of the sorted array                     
                    high = mid-1;
                }else{
                        // go to unsorted portion
                        low = mid+1;
                }
            }
            else{
                //else this part is sorted   
                if(target>=nums[mid] && target<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
                
            }
        }
        return false;
    }
};