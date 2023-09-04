//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int help(int i,vector<int>&cost,int N,vector<int>&mem){
        if(i >= N)return 0;
        if(mem[i] != -1)return mem[i];
        
        int c = cost[i];
        c += min(help(i+1,cost,N,mem),help(i+2,cost,N,mem));
        mem[i] = c;
        return mem[i];
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
       vector<int>mem(N+1,-1);
       return min(help(0,cost,N,mem),help(1,cost,N,mem));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends