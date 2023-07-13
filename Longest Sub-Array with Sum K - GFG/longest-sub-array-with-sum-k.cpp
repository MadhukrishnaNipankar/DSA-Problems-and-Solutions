//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int K) 
    { 
        unordered_map<int,int>hash;
        
        int currentSum = 0;
        int longestSequence = 0;
        
        for(int i=0;i<n;i++){
            currentSum+=A[i];//15
            
            if(currentSum == K){
                longestSequence = max(longestSequence,i+1);
            }
            
            if(hash.find(currentSum-K) != hash.end()){
                //if the sum is already present in the hashmap
                longestSequence = max(longestSequence,i-hash[currentSum-K]);
            }
            
            if (hash.find(currentSum) == hash.end()) {
                 // if the sum is not present in the hashmap, store the sum along with their indeice
                 hash[currentSum] = i;
                }
               
        }
        
        return longestSequence;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends