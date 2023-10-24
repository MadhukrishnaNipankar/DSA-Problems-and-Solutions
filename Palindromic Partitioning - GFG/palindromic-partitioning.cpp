//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool checkPalindrome(int low,int high,string str){
        while(low<=high){
            if(str[low] != str[high])return false;
            low++;
            high--;
        }
        return true;
    }
    int help(int index,string str,vector<int>&dp){
        if(index == str.size())return 0;
        if(dp[index]!= -1)return dp[index];
        
        int mini = INT_MAX;
        for(int j=index;j<str.size();j++){
            if(checkPalindrome(index,j,str)){
                mini = min(mini,1+help(j+1,str,dp));
            }
        }
        
        
        return  dp[index] = mini;
    }
    int palindromicPartition(string str)
    {
        vector<int>dp(str.size(),-1);
        int index = 0;
        return help(index,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends