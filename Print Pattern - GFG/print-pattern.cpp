//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void help1(int &N,vector<int>&ans){
        
        if(N <= 0)return;
        
        ans.push_back(N);
        N-=5;
        help1(N,ans);
        
    }
     void help2(int i,int &N,vector<int>&ans){
        
        if(i == N){
            ans.push_back(i);
            return;
        }
        
        ans.push_back(i);
        help2(i+5,N,ans);
        
    }
    vector<int> pattern(int N){
        int originalN = N;
        vector<int>ans;
        help1(N,ans);
        help2(N,originalN,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends