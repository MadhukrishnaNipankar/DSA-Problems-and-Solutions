class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // If the array is not rotated (minimum element is the first element)
        if (nums[low] < nums[high]) {
            return nums[low];
        }
        
        // Binary search for the smallest element
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) {
                // Minimum must be in the right part
                low = mid + 1;
            } else {
                // Minimum could be mid or in the left part
                high = mid;
            }
        }
        
        // After exiting the loop, low should be pointing to the minimum element
        return nums[low];
    }
};
