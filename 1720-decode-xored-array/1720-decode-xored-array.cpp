class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first); // as the first element of the ans array is given
        for(int i=0;i<encoded.size();i++)
        {
            int x=ans[i]^encoded[i]; // calculating the next elements using the concept above
            ans.push_back(x);
        }
        return ans;
    }
};