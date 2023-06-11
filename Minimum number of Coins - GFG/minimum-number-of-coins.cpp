//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int>result;
        int amount = N;
        int denomination[] = {2000,500,200,100,50,20,10,5,2,1};
        int i = 0;
        while(i>=0 && amount>0){
            if(amount>=denomination[i]){
                amount-=denomination[i];
                result.push_back(denomination[i]);
            }
            else{
                i++;
            }
        }
    
        return result;
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
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends