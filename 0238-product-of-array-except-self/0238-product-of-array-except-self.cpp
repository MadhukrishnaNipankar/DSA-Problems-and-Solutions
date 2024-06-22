class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Initialize the result array with 1s
    vector<int> result(n, 1);
    
    // Step 2: Compute prefix products
    int prefixProduct = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefixProduct;
        prefixProduct *= nums[i];
    }
    
    // Step 3: Compute suffix products
    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }
    
    return result;
}
       
};