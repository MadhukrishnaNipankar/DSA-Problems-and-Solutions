class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> answer {0,1};
        if(n == 1)
            return answer;

        //1]sorting
        sort(nums.begin(), nums.end());
        
        //counting pairs and leftovers
        int pairs = 0, i = 1;
        
        while(i<nums.size()){
            if(nums[i-1]== nums[i]){
                pairs++;
                i+=2;
            }
            else{
                i++;
            }
        }

        
        answer.at(0) = pairs;
        answer.at(1) = n-(pairs*2); //leftovers 
        
        return answer; 
    }
};