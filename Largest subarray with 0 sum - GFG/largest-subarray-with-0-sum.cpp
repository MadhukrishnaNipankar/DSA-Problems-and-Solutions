//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>hash;
        
        int currentSum = 0;
        int longestSequence = 0;
        
        for(int i=0;i<n;i++){
            currentSum+=A[i];//15
            
            if(currentSum == 0){
                longestSequence = max(longestSequence,i+1);
            }
            
            if(hash.find(currentSum) != hash.end()){
                //if the sum is already present in the hashmap
                longestSequence = max(longestSequence,i-hash[currentSum]);
            }else{
                // if the sum is not present in the hashmap, store the sum along with their indeice
                hash[currentSum] = i;
            }
        }
        
        return longestSequence;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends