//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
     void helper(int i,vector<int>&input,vector<int>&temp,vector<vector<int>>&ans){
        if(i >= input.size()){
            ans.push_back(temp);
            return;
        }


        // take the ith element
        temp.push_back(input[i]);
        helper(i+1,input,temp,ans);

        // dont take the ith element
        temp.pop_back();
        while(i+1<input.size() && input[i] == input[i+1])i++;
        helper(i+1,input,temp,ans);
       
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,nums,temp,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends