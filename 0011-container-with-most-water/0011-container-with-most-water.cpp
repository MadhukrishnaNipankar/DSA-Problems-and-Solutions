class Solution {
public:
    //bruteforce. trying area for each container : O(n^2)
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int result = INT_MIN;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int area = (j-i)*min(height[i],height[j]);
//                 result = max(area,result);
//             }
//         }
        
//         return result;
//     }
    
    
    //Using Two Pointers: O(n) 
    int maxArea(vector<int>& height) {
        int n = height.size();
        int result = INT_MIN;
        int i = 0,j=n-1;
        while(i<n){
            int area = (j-i)*min(height[i],height[j]);
            result = max(result,area);
            if(height[i]>height[j])j--;
            else i++;
        }
        return result;
    }
};